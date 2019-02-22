/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include <cstdlib>
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
	movesWithoutBreeding = -8;
	grid = nullptr;
}

/**
 * Default constructor for a Doodlebug object which has row r and column c
 * @param r The row of the doodlebug
 * @param c The column of the doodlebug
 */
Doodlebug::Doodlebug(int r, int c, Grid* grid) {
	// TODO Auto-generated constructor stub
	this->r = r;
	this->c = c;
	stepsTilStarve = 3;
	movesWithoutBreeding = -8;
	this->grid = grid;
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
	bool hasMoved = false;
	int numEmptyAdjacents = 0; // the number of empty adjacent cells
	bool canMoveNorth = this->canMoveHere(0, grid, r, c); // space to the north occupied?
	bool canMoveEast = this->canMoveHere(1, grid, r, c); // space to the east occupied?
	bool canMoveSouth = this->canMoveHere(2, grid, r, c); // space to the south occupied?
	bool canMoveWest = this->canMoveHere(3, grid, r, c); // space to the west occupied?

	if(canMoveNorth) { numEmptyAdjacents++; }
	if(canMoveEast) { numEmptyAdjacents++; }
	if(canMoveSouth) { numEmptyAdjacents++; }
	if(canMoveWest) { numEmptyAdjacents++; }

	if(movesWithoutBreeding >= 0 && numEmptyAdjacents) { // if the doodlebug has to breed and there are available adjacent spaces
		while(!hasMoved) {
			int randomInt = (int)(rand() % (numEmptyAdjacents + 1)); // generates a random int from 0 to 3
			if(canMoveNorth) {
				if(randomInt == numEmptyAdjacents) {
					new Doodlebug(r-1, c, grid);
					hasMoved = true;
				}
			}
			if(canMoveEast) {
				if(randomInt == numEmptyAdjacents + 1) {
					new Doodlebug(r, c+1, grid);
					hasMoved = true;
				}
			}
			if(canMoveSouth) {
				if(randomInt == numEmptyAdjacents + 2) {
					new Doodlebug(r+1, c, grid);
					hasMoved = true;
				}
			}
			if(canMoveWest) {
				if(randomInt == numEmptyAdjacents + 3) {
					new Doodlebug(r, c-1, grid);
					hasMoved = true;
				}
			}
		}
	}

	if(hasMoved == true) {
		movesWithoutBreeding = -8;
		delete(this);
		grid->numDoodlebugs++;
	}
	return hasMoved;
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
	bool hasBred = false;
	int numEmptyAdjacents = 0; // the number of empty adjacent cells
	bool canBreedNorth = this->canMoveHere(0, grid, r, c); // space to the north occupied?
	bool canBreedEast = this->canMoveHere(1, grid, r, c); // space to the east occupied?
	bool canBreedSouth = this->canMoveHere(2, grid, r, c); // space to the south occupied?
	bool canBreedWest = this->canMoveHere(3, grid, r, c); // space to the west occupied?

	if(canBreedNorth) { numEmptyAdjacents++; }
	if(canBreedEast) { numEmptyAdjacents++; }
	if(canBreedSouth) { numEmptyAdjacents++; }
	if(canBreedWest) { numEmptyAdjacents++; }

	if(movesWithoutBreeding >= 0 && numEmptyAdjacents) { // if the doodlebug has to breed and there are available adjacent spaces
		while(!hasBred) {
			int randomInt = (int)(rand() % (numEmptyAdjacents + 1)); // generates a random int from 0 to 3
			if(canBreedNorth) {
				if(randomInt == numEmptyAdjacents) {
					new Doodlebug(r-1, c, grid);
					hasBred = true;
				}
			}
			if(canBreedEast) {
				if(randomInt == numEmptyAdjacents + 1) {
					new Doodlebug(r, c+1, grid);
					hasBred = true;
				}
			}
			if(canBreedSouth) {
				if(randomInt == numEmptyAdjacents + 2) {
					new Doodlebug(r+1, c, grid);
					hasBred = true;
				}
			}
			if(canBreedWest) {
				if(randomInt == numEmptyAdjacents + 3) {
					new Doodlebug(r, c-1, grid);
					hasBred = true;
				}
			}
		}
	}

	if(hasBred == true) {
		movesWithoutBreeding = -8;
		grid->numDoodlebugs++;
	}
	return hasBred;
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
 * Causes the Doodlebug to take a step, i.e. move and/or breed
 */
void Doodlebug::step(Grid* grid) {
	this->move(grid);
	this->breed(grid);
}

/**
 * Default destructor method for a Doodlebug
 * Removes the Doodlebug from the board and from its space held in memory
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
	grid->numDoodlebugs--;
}

