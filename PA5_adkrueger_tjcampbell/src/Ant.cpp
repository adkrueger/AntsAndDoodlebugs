/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Ant.h"

/**
 * Default constructor for an Ant object
 */
Ant::Ant()
:Organism(true) {

}

/**
 * Constructs an Ant object at a certain location on the grid
 * @param r The row of the Ant
 * @param c the column of the Ant
 */
Ant::Ant(int r, int c)
:Organism(true) {
	row = r;
	col = c;
}

/**
 * Moves the Ant to a nearby cell.
 * If the Ant is surrounded by available adjacent cells (above, below, or to the left or
 * right of the ant), it will move to one of these at random.
 * If no cells are available, the Ant will remain in the same location.
 * @return Whether the Ant moved successfully
 */
bool Ant::move() {
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
bool Ant::breed() {
	bool status = true;
	return status;
}

/**
 * Destructor for Ant objects
 * Clears memory formerly held by an Ant
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

