/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Aaron Krueger & Theo Campbell
 */

#include <cstdlib>
#include "Doodlebug.h"
#include "Grid.h"

/**
 * Default constructor for a Doodlebug object
 */
Doodlebug::Doodlebug() {
	r = 0; // default row value of the doodle
	c = 0; // default col value of the doodle
	stepsTilStarve = 3; // default number of steps til the doodle starves (decremented)
	movesWithoutBreeding = -8; // default number of moves til the doodle breeds (incremented)
	grid = nullptr;
}

/**
 * Default constructor for a Doodlebug object which has row r and column c
 * @param r The row of the doodlebug
 * @param c The column of the doodlebug
 */
Doodlebug::Doodlebug(int r, int c, Grid* grid) {
	this->r = r; // setting the row value
	this->c = c; // setting the col value
	stepsTilStarve = 3; // default number of steps til the doodle starves (decremented)
	movesWithoutBreeding = -8; // default number of moves til the doodle breeds (incremented)
	this->grid = grid; // setting the grid
	this->grid->setCellOccupant(r, c, this); // adding the doodle to the grid
	this->grid->getCellOccupant(r, c)->setAmAnt(false); // setting the amAnt value of the organism in the grid
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
	bool hasMoved = false; // whether the doodle moved
	bool hasEaten = false; // whether the doodle ate
	int numAvailableAdjacents = 0; // the number of empty adjacent cells
	bool canMoveNorth = doodleCanMoveHere(0, grid, r, c); // space to the north occupied?
	bool canMoveEast = doodleCanMoveHere(1, grid, r, c); // space to the east occupied?
	bool canMoveSouth = doodleCanMoveHere(2, grid, r, c); // space to the south occupied?
	bool canMoveWest = doodleCanMoveHere(3, grid, r, c); // space to the west occupied?

	if(canMoveNorth) { numAvailableAdjacents++; } // determine the correct number of available adjacent spaces
	if(canMoveEast) { numAvailableAdjacents++; }
	if(canMoveSouth) { numAvailableAdjacents++; }
	if(canMoveWest) { numAvailableAdjacents++; }


	if(numAvailableAdjacents) { // if the doodlebug has to breed and there are available adjacent spaces
		while(!hasMoved) {
			int randomInt = (int)(rand() % 4); // generates a random int from 0 to 3
			if(canMoveNorth && canMoveHere(0, grid, r, c) && !hasMoved) { // if we can move north and there isn't an organism occupying that spot
				if(randomInt == 0) {
					grid->setCellOccupant(r-1, c, this); // move the doodlebug north by creating an doodlebug in its place
					grid->setCellOccupant(r, c, nullptr); // remove the doodlebug from its current spot
					r--;
					hasMoved = true;
				}
			}
			else if (canMoveNorth && r-1 >= 0 && grid->getCellOccupant(r-1, c)->isPrey() && !hasMoved) { // if the move is blocked by an Ant, eat it
				eat(grid, r-1, c);
				grid->setCellOccupant(r, c, nullptr); // remove the doodlebug from its current spot
				r--;
				hasMoved = true;
				hasEaten = true;
			}
			if(canMoveEast && canMoveHere(1, grid, r, c) && !hasMoved) { // if we can move east and there isn't an organism occupying that spot
				if(randomInt == 1) {
					grid->setCellOccupant(r, c+1, this); // move the doodlebug east by creating an doodlebug in its place
					grid->setCellOccupant(r, c, nullptr); // remove the doodlebug from its current spot
					c++;
					hasMoved = true;
				}
			}
			else if (canMoveEast && c+1 < grid->n && grid->getCellOccupant(r-1, c)->isPrey() && !hasMoved) { // if the move is blocked by an Ant, eat it
				eat(grid, r, c+1);
				grid->setCellOccupant(r, c, nullptr); // remove the doodlebug from its current spot
		        c++;
				hasMoved = true;
				hasEaten = true;
			}
			if(canMoveSouth && canMoveHere(2, grid, r, c) && !hasMoved) { // if we can move south and there isn't an organism occupying that spot
				if(randomInt == 2) {
					grid->setCellOccupant(r+1, c, this); // move the doodlebug south by creating an doodlebug in its place
					grid->setCellOccupant(r, c, nullptr); // remove the doodlebug from its current spot
					r++;
					hasMoved = true;
				}
			}
			else if (canMoveSouth && r+1 < grid->n && grid->getCellOccupant(r-1, c)->isPrey() && !hasMoved) { // if the move is blocked by an Ant, eat it
			    eat(grid, r+1, c);
				grid->setCellOccupant(r, c, nullptr); // remove the doodlebug from its current spot
				r++;
				hasMoved = true;
				hasEaten = true;
			}
			if(canMoveWest && canMoveHere(3, grid, r, c) && !hasMoved) { // if we can move west and there isn't an organism occupying that spot
				if(randomInt == 3) {
					grid->setCellOccupant(r, c-1, this); // move the doodlebug west by creating an doodlebug in its place
					grid->setCellOccupant(r, c, nullptr); // remove the doodlebug from its current spot
					c--;
					hasMoved = true;
				}
			}
			else if (canMoveWest && c-1 >= 0 && grid->getCellOccupant(r-1, c)->isPrey() && !hasMoved) { // if the move is blocked by an Ant, eat it
				eat(grid, r, c-1);
				grid->setCellOccupant(r, c, nullptr); // remove the doodlebug from its current spot
				c--;
				hasMoved = true;
				hasEaten = true;
			}
		}
	}

	movesWithoutBreeding++; // increment the number of steps the doodle hasn't bred in

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

	if(numEmptyAdjacents) { // if the doodlebug has to breed and there are available adjacent spaces
		while(!hasBred) {
			int randomInt = (int)(rand() % 4); // generates a random int from 0 to numEmptyAdjacents
			if(canBreedNorth) { // if the doodle can breed to the north
				if(randomInt == 0) {
					grid->setCellOccupant(r-1, c, new Doodlebug(r-1, c, grid)); // create a new Doodlebug to the north
					hasBred = true;
				}
			}
			if(canBreedEast) { // if the doodle can breed to the east
				if(randomInt == 1) {
					grid->setCellOccupant(r, c+1, new Doodlebug(r, c+1, grid)); // create a new Doodlebug to the east
					hasBred = true;
				}
			}
			if(canBreedSouth) { // if the doodle can breed to the south
				if(randomInt == 2) {
					grid->setCellOccupant(r+1, c, new Doodlebug(r+1, c, grid)); // create a new Doodlebug to the south
					hasBred = true;
				}
			}
			if(canBreedWest) { // if the doodle can breed to the west
				if(randomInt == 3) {
					grid->setCellOccupant(r, c-1, new Doodlebug(r, c-1, grid)); // create a new Doodlebug to the west
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

	grid->numAnts--;
	delete grid->getCellOccupant(r, c); // delete the ant in the space
	grid->setCellOccupant(r, c, this); // then move the doodlebug there
	stepsTilStarve = 3;

	return status;
}

/**
 * Causes the Doodlebug to take a step, i.e. move and/or breed
 */
void Doodlebug::step(Grid* grid) {
	this->move(grid); // have the doodle move
	if(this->starve()) { // if the doodle starves, then remove it
		grid->numDoodlebugs--;
		delete this;
	}
	else if(movesWithoutBreeding >= 0){ // otherwise have it attempt to breed
		this->breed(grid);
	}
}

/**
 * Checks whether the Doodlebug will starve
 * @return true if the Doodlebug starved, false otherwise
 */
bool Doodlebug::starve() {
	return(stepsTilStarve <= 0);
}

/**
 * Default destructor method for a Doodlebug
 * Removes the Doodlebug from the board and from its space held in memory
 */
Doodlebug::~Doodlebug() {
	grid->setCellOccupant(r, c, (Organism*)nullptr);
}

