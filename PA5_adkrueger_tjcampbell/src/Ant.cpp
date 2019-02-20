/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Ant.h"
#include "Grid.h"


/**
 * Default constructor for an Ant object
 */
Ant::Ant()
:Organism(true) {
    row = 0;
    col = 0;
    movesWithoutBreeding = -3;
    grid = nullptr;
}

/**
 * Constructs an Ant object at a certain location on the grid
 * @param r The row of the Ant
 * @param c the column of the Ant
 */
Ant::Ant(int r, int c, Grid* grid)
:Organism(true) {
	row = r;
	col = c;
	movesWithoutBreeding = -3;
	this->grid = grid;
}

/**
 * Moves the Ant to a nearby cell.
 * If the Ant is surrounded by available adjacent cells (above, below, or to the left or
 * right of the ant), it will move to one of these at random.
 * If no cells are available, the Ant will remain in the same location.
 * @return Whether the Ant moved successfully
 */
bool Ant::move(Grid* grid) {
	bool status = true;
	return status;
}

/**
 * Creates another Ant object.
 * If an Ant survives three time steps, it will reproduce and create another
 * Ant in an adjacent cell.
 * If no adjacent cells are available, the Ant will wait until the next
 * available turn to create another ant.
 * If multiple adjacent cells are available, the Ant will choose at random
 * which adjacent cell it will create another Ant.
 * @return whether or not the Ant was created successfully
 */
bool Ant::breed(Grid* grid) {
	bool status = false;

	if(movesWithoutBreeding >= 0) {
		status = true;
	}

	if(status == true) {
		movesWithoutBreeding = -8;
	}
	return status;
}

/**
 * Destructor for Ant objects
 * Clears memory formerly held by an Ant
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

