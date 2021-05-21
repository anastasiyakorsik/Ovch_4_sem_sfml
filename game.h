#pragma once

// Resolution of the sreen
const unsigned int RES_WIDTH = 1800;
const unsigned int RES_HEIGHT = 1000;

// Max amount of caught plums
const unsigned int MAX_PLUMS = 1000;

// Enum class for initializing moving direction
enum class direction_t {
	ERROR, LEFT, RIGHT, UP, DOWN, COUNT
};