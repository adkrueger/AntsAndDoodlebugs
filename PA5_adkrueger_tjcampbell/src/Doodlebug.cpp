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
	bool hasEaten = false;
	int numAvailableAdjacents = 0; // the number of empty adjacent cells
	bool canMoveNorth = this->doodleCanMoveHere(0, grid, r, c); // space to the north occupied?
	bool canMoveEast = this->doodleCanMoveHere(1, grid, r, c); // space to the east occupied?
	bool canMoveSouth = this->doodleCanMoveHere(2, grid, r, c); // space to the south occupied?
	bool canMoveWest = this->doodleCanMoveHere(3, grid, r, c); // space to the west occupied?

	if(canMoveNorth) { numAvailableAdjacents++; } // determine the correct number of available adjacent spaces
	if(canMoveEast) { numAvailableAdjacents++; }
	if(canMoveSouth) { numAvailableAdjacents++; }
	if(canMoveWest) { numAvailableAdjacents++; }


	if(numAvailableAdjacents) { // if the doodlebug has to breed and there are available adjacent spaces
		if(!hasMoved) {
			int randomInt = (int)(rand() % (numAvailableAdjacents + 1)); // generates a random int from 0 to 3
			if(canMoveNorth && !hasMoved) { // if we can move north and haven't moved yet
				if(randomInt == numAvailableAdjacents) {
					grid->setCellOccupant(r-1, c, this); // move the Ant north by creating an Ant in its place
					r--;
					hasMoved = true;
				}
			}
			else if (r-1 >= 0 && grid->getCellOccupant(r-1, c)->isPrey() && !hasMoved) { // if the move is blocked by an Ant, eat it
				this->eat(grid, r-1, c);
				r--;
				hasMoved = true;
				hasEaten = true;
			}
			if(canMoveEast && !hasMoved) { // if we can move east and haven't moved yet
				if(randomInt == numAvailableAdjacents + 1) {
					grid->setCellOccupant(r, c+1, this); // move the Ant east by creating an Ant in its place
					c++;
					hasMoved = true;
				}
			}
			else if (c+1 < grid->n && grid->getCellOccupant(r-1, c)->isPrey() && !hasMoved) { // if the move is blocked by an Ant, eat it
				this->eat(grid, r, c+1);
		        c++;
				hasMoved = true;
				hasEaten = true;
			}
			if(canMoveSouth && !hasMoved) { // if we can move south and haven't moved yet
				if(randomInt == numAvailableAdjacents + 2) {
					grid->setCellOccupant(r+1, c, this); // move the Ant south by creating an Ant in its place
					r++;
					hasMoved = true;
				}
			}
			else if (r+1 < grid->n && grid->getCellOccupant(r-1, c)->isPrey() && !hasMoved) { // if the move is blocked by an Ant, eat it
				this->eat(grid, r+1, c);
				r++;
				hasMoved = true;
				hasEaten = true;
			}
			if(canMoveWest && !hasMoved) { // if we can move west and haven't moved yet
				if(randomInt == numAvailableAdjacents + 3) {
					grid->setCellOccupant(r, c-1, this); // move the Ant west by creating an Ant in its place
					c--;
					hasMoved = true;
				}
			}
			else if (c-1 >= 0 && grid->getCellOccupant(r-1, c)->isPrey() && !hasMoved) { // if the move is blocked by an Ant, eat it
				this->eat(grid, r, c-1);
				c--;
				hasMoved = true;
				hasEaten = true;
			}
		}
	}

	if(hasMoved == true) {
		movesWithoutBreeding++;
		grid->numDoodlebugs++;
	}
	if(hasEaten == true) { // if the doodlebug has eaten, reset its starvation counter
		stepsTilStarve = 3;
	}
	else { // otherwise, decrement it
		stepsTilStarve--;
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

	if(canBreedNorth) { numEmptyAdjacents++; } // find the correct number of empty adjacent cells
	if(canBreedEast) { numEmptyAdjacents++; }
	if(canBreedSouth) { numEmptyAdjacents++; }
	if(canBreedWest) { numEmptyAdjacents++; }

	if(movesWithoutBreeding >= 0 && numEmptyAdjacents) { // if the doodlebug has to breed and there are available adjacent spaces
		if(!hasBred) {
			int randomInt = (int)(rand() % (numEmptyAdjacents + 1)); // generates a random int from 0 to numEmptyAdjacents
			if(canBreedNorth) {
				if(randomInt == numEmptyAdjacents) {
					grid->setCellOccupant(r, c, new Doodlebug(r-1, c, grid)); // create a new Doodlebug to the north
					hasBred = true;
				}
			}
			if(canBreedEast) {
				if(randomInt == numEmptyAdjacents + 1) {
					grid->setCellOccupant(r, c, new Doodlebug(r, c+1, grid)); // create a new Doodlebug to the east
					hasBred = true;
				}
			}
			if(canBreedSouth) {
				if(randomInt == numEmptyAdjacents + 2) {
					grid->setCellOccupant(r, c, new Doodlebug(r+1, c, grid)); // create a new Doodlebug to the south
					hasBred = true;
				}
			}
			if(canBreedWest) {
				if(randomInt == numEmptyAdjacents + 3) {
					grid->setCellOccupant(r, c, new Doodlebug(r, c-1, grid)); // create a new Doodlebug to the west
					hasBred = true;
				}
			}
		}
	}

	if(hasBred == true) { // if the doodlebug bred
		movesWithoutBreeding = -8; // reset the breeding counter
		grid->numDoodlebugs++; // increment the number of doodlebugs on the board
	}
	return hasBred;
}

/**
 * Consumes an Ant, moving into its space and removing it from the board
 * @param grid The home grid for the doodlebug
 * @param r The row of the Ant
 * @param c The column of the Ant
 * @return Whether or not the Ant was eaten successfully
 */
bool Doodlebug::eat(Grid* grid, int r, int c) {
	bool status = true;

	delete(grid->getCellOccupant(r, c)); // delete the ant in the space
	grid->setCellOccupant(r, c, this); // then move the doodlebug there

	return status;
}

/**
 * Causes the Doodlebug to take a step, i.e. move and/or breed
 */
void Doodlebug::step(Grid* grid) {
	this->move(grid);
	if(this->starve()) {
		delete(this);
	}
	else {
		this->breed(grid);
	}
}

/**
 * Checks whether the Doodlebug will starve
 * @return true if the Doodlebug starved, false otherwise
 */
bool Doodlebug::starve() {
	return(this->stepsTilStarve <= 0);
}

/**
 * Default destructor method for a Doodlebug
 * Removes the Doodlebug from the board and from its space held in memory
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
	grid->numDoodlebugs--;
	grid->setCellOccupant(r, c, (Organism*)nullptr);
}

