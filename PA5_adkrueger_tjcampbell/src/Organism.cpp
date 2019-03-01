/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Aaron Krueger & Theo Campbell
 */

#include "Organism.h"

/**
 * Default constructor for an Organism
 */
Organism::Organism() {
	movesWithoutBreeding = 0; // the default moves without breeding
	r = 0; // the default row of the organism
	c = 0; // the default row of the organism
	grid = nullptr; // setting the grid to null
}

/**
 * Constructor for an Organism, which may or may not be an Ant
 * @param b Whether or not the Organism is an Ant
 */
Organism::Organism(bool b) {
	amAnt = b; // whether the organism is an ant
	movesWithoutBreeding = 0; // how many moves are left until the organism breeds (fully initiated in derived classes)
	r = 0; // the row position of the organism (fully initiated in derived classes)
	c = 0; // the col position of the organism  (fully initiated in derived classes)
	grid = nullptr;
}

/**
 * Whether or not the Organism is an Ant
 * @return true if the Organism is an Ant or nullptr
 *         false if the Organism is not an Ant
 */
bool Organism::isPrey() {
	return (this == nullptr || amAnt); // error thrown here doesn't make sense - checked online and it appears to be buggy/too strict
}

/**
 * Sets the status of an Organism to being an Ant or not being an Ant
 * @param b Whether or not the Organism is an Ant
 */
void Organism::setAmAnt(bool b) {
	amAnt = b;
}

/**
 * Checks whether or not the given Cell is occupied by something.
 * @param grid The grid that will be checked
 * @return true if there is nothing in the given space, false otherwise
 */
bool Organism::isEmpty(Grid* grid, int r, int c) {
	return (grid->getCellOccupant(r, c) == nullptr); // true if the space is empty
}

/**
 * Checks if the organism is able to move in the direction specified by direction.
 * direction follows cardinal directions, i.e.
 * 0 = north, 1 = east
 * 2 = south, 3 = west
 * Different from isEmpty because it checks whether the given space is within
 * the bounds of the grid.
 * @param direction The cardinal direction that the organism will be moving in
 * @param g The grid that will be checked
 * @param r The row of the organism
 * @param c The column of the organism
 * @return true if the organism can move to this space, false otherwise
 */
bool Organism::canMoveHere(int direction, Grid* g, int r, int c) {
	bool available = false;

	if(direction == 0 && r-1 >= 0 && g->getCellOccupant(r-1, c)->isEmpty(g, r-1, c)) { // if the space to the north is empty
		available = true;
	}
	if(direction == 1 && c+1 < g->n && g->getCellOccupant(r, c+1)->isEmpty(g, r, c+1)) { // if the space to the east is empty
		available = true;
	}
	if(direction == 2 && r+1 < g->n && g->getCellOccupant(r+1, c)->isEmpty(g, r+1, c)) { // if the space to the south is empty
		available = true;
	}
	if(direction == 3 && c-1 >= 0&& g->getCellOccupant(r, c-1)->isEmpty(g, r, c-1)) { // if the space to the wast is empty
		available = true;
	}

	return available;
}

/**
 * Checks if the doodlebug is able to move in the direction specified by direction.
 * direction follows cardinal directions, i.e.
 * 0 = north, 1 = east
 * 2 = south, 3 = west
 * Different from isEmpty because it checks whether the given space is within
 * the bounds of the grid.
 * Different from canMoveHere because it checks whether or not the space is occupied
 * by an ant
 * @param direction The cardinal direction that the organism will be moving in
 * @param g The grid that will be checked
 * @param r The row of the organism
 * @param c The column of the organism
 * @return true if the doodlebug can move to this space, false otherwise
 */
bool Organism::doodleCanMoveHere(int direction, Grid* g, int r, int c) {
	bool available = false;

	if(r-1 >= 0 && direction == 0 && g->getCellOccupant(r-1, c)->isPrey()) { // if the space to the north is prey or empty
		available = true;
	}
	if(c+1 < g->n && direction == 1 && g->getCellOccupant(r, c+1)->isPrey()) { // if the space to the east is prey or empty
		available = true;
	}
	if(r+1 < g->n && direction == 2 && g->getCellOccupant(r+1, c)->isPrey()) { // if the space to the south is prey or empty
		available = true;
	}
	if(c-1 >= 0 && direction == 3 && g->getCellOccupant(r, c-1)->isPrey()) { // if the space to the west is prey or empty
		available = true;
	}

	return available;
}

/**
 * Destructor for an Organism
 * Removes the Organism from the Grid and memory
 */
Organism::~Organism() {
    grid->setCellOccupant(r, c, (Organism*)nullptr);
}

