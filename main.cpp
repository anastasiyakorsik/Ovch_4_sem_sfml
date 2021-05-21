#include "player.h"
#include "map.h"
#include "projectile.h"
#include "game.h"
#include "Villian.h"
#include "-3brs.h"

#include <iostream>
#include <vector>

using namespace sf;

void next_state(state_t& state) {
    state = static_cast<state_t>(static_cast<int>(state) + 1);
}

int main()
{
    // Style::Fullscreen
    RenderWindow window(VideoMode(RES_WIDTH, RES_HEIGHT), "Ovch");
    // Creating player's and villian's sprites
    Player player("ovch.png", 0.7, 50, 50);
    Villian villian("koldun.png", 0.7, 100, 100);
    
    state_t state = state_t::ERROR;
    bool update_state = false;

    Map map;
    map.CreateMap();

    unsigned int plums_amount = 0;
    unsigned int projectiles_amount = 0;

    float x_villian = rand();
    float y_villian = rand();

    Clock clock;
    int x = rand() % 18, y = rand() % 10 + 1;
    int N = 0, k = 0;
    bool count = false;
    // Creating books vector
    std::vector<Projectile*> projectiles;
    double Time = 5000;
    double Time_2 = 5000;

    // Creating brs vector
    std::vector<Brs*> brs_vec;

    float shoot_cd = 0;

    SoundBuffer buffer1, buffer2, buffer3, buffer4;
    buffer1.loadFromFile("ovch1.ogg");
    buffer2.loadFromFile("ovch2.ogg");
    buffer3.loadFromFile("ovch3.ogg");
    buffer4.loadFromFile("ovch4.ogg");

    Sound sound1(buffer1);
    Sound sound2(buffer2);
    Sound sound3(buffer3);
    Sound sound4(buffer4);

    // Launch the loop
    state = state_t::FIRST;
    while (window.isOpen())
    {
        // Count elapsed time
        double time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        
        // Handle events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        double dr = player.step * time;

        map.TileMap[y][x] = ' ';

        // Process keyboard
        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        if(Keyboard::isKeyPressed(Keyboard::W)) {
            player.update(0, -dr, time, direction_t::UP);
        }

        if(Keyboard::isKeyPressed(Keyboard::A)) {
            player.update(-dr, 0, time, direction_t::LEFT);
        }

        if(Keyboard::isKeyPressed(Keyboard::S)) {
            player.update(0, dr, time, direction_t::DOWN);
        }

        if(Keyboard::isKeyPressed(Keyboard::D)) {
            player.update(dr, 0, time, direction_t::RIGHT);
        }

        if(Time > 200 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            Time = 0;
            Projectile* projectile;
            projectile = new Projectile;
            projectile->changeState(state);
            projectile->x = player.x, projectile->y = player.y;
            projectile->projsprite.setPosition(player.x, player.y);

            switch (player.dir) {
                case direction_t::UP:
                    projectile->velocity_x = 0, projectile->velocity_y = -1;
                    break;
                case direction_t::LEFT:
                    projectile->velocity_x = -1, projectile->velocity_y = 0;
                    break;
                case direction_t::DOWN:
                    projectile->velocity_x = 0, projectile->velocity_y = 1;
                    break;
                case direction_t::RIGHT:
                    projectile->velocity_x = 1, projectile->velocity_y = 0;
                    break;
                default:
                    throw std::runtime_error("Unknown direction!");
            }

            projectiles.push_back(projectile);
            count = true;

            //counting the number of hits on the villian
            if ((projectile->x > 95 * villian.x - 47.5) && (projectile->x < 95 * villian.x + 47.5) && (projectile->y + 62 > 95 * villian.y - 47.5) && (projectile->y + 62 < 95 * villian.y + 47.5))
            {
                projectiles_amount++;
            }
        }

        for (auto&& projectile : projectiles) {
            projectile->update(time);
        }

        // Update time
        if (count)
            Time += time;

        // Change the state of all projectiles according to the number of caught plums
        if (update_state && state != state_t::FOURTH && (plums_amount % 2 == 0)) {
            next_state(state);

            for (auto& projectile : projectiles) {
                projectile->changeState(state);
            }      

            update_state = false;
        }

        // Appearance of villian when up to 4th level
        if (state == state_t::FOURTH) {
            if ((villian.x > RES_WIDTH - 300) && villian.dir == direction_t::RIGHT)
                villian.dir = direction_t::LEFT;
            if ((villian.x < 100) && villian.dir == direction_t::LEFT)
                villian.dir = direction_t::RIGHT;
            if (Time_2 > 500) {
                Time_2 = 0;
                Brs* brs;
                brs = new Brs;
                brs->x = villian.x, brs->y = villian.y + 120;
                brs->sprite.setPosition(villian.x, villian.y + 120);
                brs->velocity_x = 0, brs->velocity_y = 40;
                brs_vec.push_back(brs);
                for (auto&& brs : brs_vec) {
                    brs->update(time);
                }
                count = true;
            }
            if (count)
                Time_2 += time;
        }

        villian.update(dr, 0, time);

        window.clear();

        // Map drawing
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++)
                {
                    if(map.TileMap[i][j] == '0') 
                        map.mapSprite.setTextureRect(IntRect(0, 0, 95, 95));
                    if(map.TileMap[i][j] == ' ')
                        map.mapSprite.setTextureRect(IntRect(95, 0, 95, 95));

                    map.mapSprite.setPosition(95 * j, 95 * i);
                    window.draw(map.mapSprite);
                }

        // Catching plums process
        if( (player.x > 95 * x - 47.5) && (player.x < 95 * x + 47.5) && (player.y + 62 > 95 * y - 47.5) && (player.y + 62 < 95 * y + 47.5) )
        {
            map.TileMap[y][x] = '0';
            x = rand() % 18;
            y = rand() % 9 + 1;
            int n = rand() % 4 + 1;
            if(n == 1)
                 sound1.play();
            if(n == 2)
                sound2.play();
            if(n == 3)
                sound3.play();
            if(n == 4)
                sound4.play();
            std::cout << "Time: " << Time << std::endl;
            update_state = true; // update the state of the book
            plums_amount++;
            std::cout << "New plum! Amount: " << plums_amount << std::endl;
        }

        if (state == state_t::FOURTH) {
            window.draw(villian.villian_sprite);
            for (auto&& brs : brs_vec)
                window.draw(brs->sprite);
        }

        for (auto&& projectile : projectiles)
            window.draw(projectile->projsprite);

        window.draw(player.herosprite);
        window.display();
    }

    //free vectors
    for (auto&& projectile : projectiles)
        delete projectile;
    for (auto&& brs : brs_vec)
        delete brs;

    return 0;
}
