/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include <cstdlib>
#include "Ant.h"
#include "Grid.h"


/**
 * Default constructor for an Ant object
 */
Ant::Ant()
:Organism(true) {
	r = 0;
	c = 0;
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
	this->r = r;
	this->c = c;
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

	if(numEmptyAdjacents) { // if there are available adjacent spaces
		while(!hasMoved) {
			int randomInt = (int)(rand() % (numEmptyAdjacents + 1)); // generates a random int from 0 to 3
			if(canMoveNorth) {
				if(randomInt == numEmptyAdjacents) {
					new Ant(r-1, c, grid);
					hasMoved = true;
				}
			}
			if(canMoveEast) {
				if(randomInt == numEmptyAdjacents + 1) {
					new Ant(r, c+1, grid);
					hasMoved = true;
				}
			}
			if(canMoveSouth) {
				if(randomInt == numEmptyAdjacents + 2) {
					new Ant(r+1, c, grid);
					hasMoved = true;
				}
			}
			if(canMoveWest) {
				if(randomInt == numEmptyAdjacents + 3) {
					new Ant(r, c-1, grid);
					hasMoved = true;
				}
			}
		}
	}

	if(hasMoved == true) {
		movesWithoutBreeding = -3;
		delete(this);
		grid->numAnts++;
	}
	return hasMoved;
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
					Ant(r-1, c, grid);
					hasBred = true;
				}
			}
			if(canBreedEast) {
				if(randomInt == numEmptyAdjacents + 1) {
					Ant(r, c+1, grid);
					hasBred = true;
				}
			}
			if(canBreedSouth) {
				if(randomInt == numEmptyAdjacents + 2) {
					new Ant(r+1, c, grid);
					hasBred = true;
				}
			}
			if(canBreedWest) {
				if(randomInt == numEmptyAdjacents + 3) {
					new Ant(r, c-1, grid);
					hasBred = true;
				}
			}
		}
	}

	if(hasBred == true) {
		movesWithoutBreeding = -3;
		grid->numAnts++;
	}
	return hasBred;
}

/**
 * Causes the Ant to take a step, i.e. move and/or breed
 */
void Ant::step(Grid* grid) {
	this->move(grid);
	this->breed(grid);
}

/**
 * Destructor for Ant objects
 * Clears memory formerly held by an Ant
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

