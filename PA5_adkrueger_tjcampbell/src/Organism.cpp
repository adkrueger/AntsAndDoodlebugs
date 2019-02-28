/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"

/**
 * Default constructor for an Organism
 */
Organism::Organism() {
	movesWithoutBreeding = 0;
	r = 0;
	c = 0;
	grid = nullptr;
}

/**
 * Constructor for an Organism, which may or may not be an Ant
 * @param b Whether or not the Organism is an Ant
 */
Organism::Organism(bool b) {
	amAnt = b;
	movesWithoutBreeding = 0;
	r = 0;
	c = 0;
	grid = nullptr;
}

/**
 * Whether or not the Organism is an Ant
 * @return true if the Organism is an Ant or nullptr
 *         false if the Organism is not an Ant
 */
bool Organism::isPrey() {
	return (this == nullptr || amAnt);
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
	return (grid->getCellOccupant(r, c) == nullptr);
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

	if(direction == 0 && r-1 >= 0 && g->getCellOccupant(r-1, c)->isEmpty(g, r-1, c)) {
		available = true;
	}
	if(direction == 1 && c+1 < g->n && g->getCellOccupant(r, c+1)->isEmpty(g, r, c+1)) {
		available = true;
	}
	if(direction == 2 && r+1 < g->n && g->getCellOccupant(r+1, c)->isEmpty(g, r+1, c)) {
		available = true;
	}
	if(direction == 3 && c-1 >= 0&& g->getCellOccupant(r, c-1)->isEmpty(g, r, c-1)) {
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

	if(r-1 >= 0 && direction == 0 && g->getCellOccupant(r-1, c)->isPrey()) {
		available = true;
	}
	if(c+1 < g->n && direction == 1 && g->getCellOccupant(r, c+1)->isPrey()) {
		available = true;
	}
	if(r+1 < g->n && direction == 2 && g->getCellOccupant(r+1, c)->isPrey()) {
		available = true;
	}
	if(c-1 >= 0 && direction == 3 && g->getCellOccupant(r, c-1)->isPrey()) {
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

