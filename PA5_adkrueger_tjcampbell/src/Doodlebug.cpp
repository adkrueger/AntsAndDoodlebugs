/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Doodlebug.h"
#include "Grid.h"

/**
 * Default constructor for a Doodlebug object
 */
Doodlebug::Doodlebug() {
	// TODO Auto-generated constructor stub
	r = 0;
	c = 0;
    stepsTilStarve = 3;
}

/**
 * Default constructor for a Doodlebug object which has row r and column c
 * @param r The row of the doodlebug
 * @param c The column of the doodlebug
 */
Doodlebug::Doodlebug(int r, int c) {
	// TODO Auto-generated constructor stub
	this->r = r;
	this->c = c;
    stepsTilStarve = 3;
}

/**
 * Moves the Doodlebug to a nearby cell, usually so that it can eat an Ant
 * If a Doodlebug is adjacent to an Ant (above, below, or to the left or
 * right of the ant), it will move to the Cell of the Ant at random and eat it.
 * If no Ants are nearby, the Doodlebug will move according to the rules of an
 * Ant moving.
 * If the Doodlebug has not eaten any Ants for three time steps, it will die
 * of starvation at the end of the third time step.
 * If no Cells are available, the Doodlebug will remain in the same location.
 * @return Whether the Doodlebug moved successfully
 */
bool Doodlebug::move(Grid* grid) {
	bool status = true;


	return status;
}

/**
 * Creates another Doodlebug object.
 * If a Doodlebug survives eight time steps, it will reproduce and create another
 * Doodlebug in an adjacent cell.
 * If no adjacent cells are available, the Doodlebug will wait until the next
 * available turn to create another Doodlebug.
 * If multiple adjacent cells are available, the Doodlebug will choose at random
 * which adjacent cell it will create another Doodlebug.
 * @return whether or not the Doodlebug was created successfully
 */
bool Doodlebug::breed(Grid* grid) {
	bool status = false;


	return status;
}

/**
 * Consumes an Ant, moving into its space and removing it from the board
 * @return Whether or not the Ant was eaten successfully
 */
bool Doodlebug::eat(Grid* grid)
{
	bool status = true;
	return status;
}

/**
 * Default destructor method for a Doodlebug
 * Removes the Doodlebug from the board and from its space held in memory
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

