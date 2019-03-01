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
	r = 0; // default: start at origin
	c = 0;
	movesWithoutBreeding = -3; // will be incremented to determine when the Ant needs to breed
	grid = nullptr; // needs a grid to start
}

/**
 * Constructs an Ant object at a certain location on the grid
 * @param r The row of the Ant
 * @param c the column of the Ant
 */
Ant::Ant(int r, int c, Grid* grid)
:Organism(true) {
	this->r = r; // the given row
	this->c = c; // the given column
	movesWithoutBreeding = -3; // will be incremented to determine when the Ant needs to breed
	this->grid = grid; // setting the grid
	this->grid->setCellOccupant(r, c, this); // add the ant to the grid
}

/**
 * Moves the Ant to a nearby cell.
 * If the Ant is surrounded by available adjacent cells (above, below, or to the left or
 * right of the ant), it will move to one of these at random.
 * If no cells are available, the Ant will remain in the same location.
 * @return Whether the Ant moved successfully
 */
bool Ant::move(Grid* grid) {
	bool hasMoved = false; // whether the ant has moved
	int numEmptyAdjacents = 0; // the number of empty adjacent cells
	bool canMoveNorth = canMoveHere(0, grid, r, c); // space to the north occupied?
	bool canMoveEast = canMoveHere(1, grid, r, c); // space to the east occupied?
	bool canMoveSouth = canMoveHere(2, grid, r, c); // space to the south occupied?
	bool canMoveWest = canMoveHere(3, grid, r, c); // space to the west occupied?

	if(canMoveNorth) { numEmptyAdjacents++; } // determining the number of empty adjacent cells
	if(canMoveEast) { numEmptyAdjacents++; }
	if(canMoveSouth) { numEmptyAdjacents++; }
	if(canMoveWest) { numEmptyAdjacents++; }

	if(numEmptyAdjacents) { // if there are available adjacent spaces
		while(!hasMoved) {
			int randomInt = (int)(rand() % 4); // generates a random int from 0 to 3
			if(canMoveNorth && !hasMoved) { // if we can move north and haven't moved yet
				if(randomInt == 0) {
					grid->setCellOccupant(r-1, c, this); // move the Ant north by creating an Ant in its place
					grid->setCellOccupant(r, c, nullptr); // remove the ant from its current spot
					r--;
					hasMoved = true;
				}
			}
			if(canMoveEast && !hasMoved) { // if we can move east and haven't moved yet
				if(randomInt == 1) {
					grid->setCellOccupant(r, c+1, this); // move the Ant east by creating an Ant in its place
					grid->setCellOccupant(r, c, nullptr); // remove the ant from its current spot
					c++;
					hasMoved = true;
				}
			}
			if(canMoveSouth && !hasMoved) { // if we can move south and haven't moved yet
				if(randomInt == 2) {
					grid->setCellOccupant(r+1, c, this); // move the Ant south by creating an Ant in its place
					grid->setCellOccupant(r, c, nullptr); // remove the ant from its current spot
					r++;
					hasMoved = true;
				}
			}
			if(canMoveWest && !hasMoved) { // if we can move west and haven't moved yet
				if(randomInt == 3) {
					grid->setCellOccupant(r, c-1, this); // move the Ant west by creating an Ant in its place
					grid->setCellOccupant(r, c, nullptr); // remove the ant from its current spot
					c--;
					hasMoved = true;
				}
			}
		}
	}

	movesWithoutBreeding++; // increment the moves without breeding
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
	bool hasBred = false; // if the doodlebug bred
	int numEmptyAdjacents = 0; // the number of empty adjacent cells
	bool canBreedNorth = canMoveHere(0, grid, r, c); // space to the north occupied?
	bool canBreedEast = canMoveHere(1, grid, r, c); // space to the east occupied?
	bool canBreedSouth = canMoveHere(2, grid, r, c); // space to the south occupied?
	bool canBreedWest = canMoveHere(3, grid, r, c); // space to the west occupied?

	if(canBreedNorth) { numEmptyAdjacents++; } // increment the number of spaces appropriately
	if(canBreedEast) { numEmptyAdjacents++; }
	if(canBreedSouth) { numEmptyAdjacents++; }
	if(canBreedWest) { numEmptyAdjacents++; }

	if(numEmptyAdjacents) { // if the doodlebug has to breed and there are available adjacent spaces
		while(!hasBred) {
			int randomInt = (int)(rand() % 4); // generates a random int from 0 to 3
			if(canBreedNorth) { // if the ant can breed to the north
				if(randomInt == 0) {
					grid->setCellOccupant(r-1, c, new Ant(r-1, c, grid)); // create a new Ant to the north
					hasBred = true;
				}
			}
			if(canBreedEast) { // if the ant can breed to the east
				if(randomInt == 1) {
					grid->setCellOccupant(r, c+1, new Ant(r, c+1, grid)); // create a new Ant to the east
					hasBred = true;
				}
			}
			if(canBreedSouth) { // if the ant can breed to the south
				if(randomInt == 2) {
					grid->setCellOccupant(r+1, c, new Ant(r+1, c, grid)); // create a new Ant to the south
					hasBred = true;
				}
			}
			if(canBreedWest) { // if the ant can breed to the west
				if(randomInt == 3) {
					grid->setCellOccupant(r, c-1, new Ant(r, c-1, grid)); // create a new Ant to the west
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
	this->move(grid); // have the ant move
	if(movesWithoutBreeding >= 0) { // if it needs to breed, have it do so
		this->breed(grid);
	}
}

/**
 * Destructor for Ant objects
 * Clears memory formerly held by an Ant
 */
Ant::~Ant() {
	grid->setCellOccupant(r, c, (Organism*)nullptr);
}

