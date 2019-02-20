/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"
bool amAnt = false;

/**
 * Default constructor for an Organism
 */
Organism::Organism() {
	stepsTilBreed = 0;
}

/**
 * Constructor for an Organism, which may or may not be an Ant
 * @param b Whether or not the Organism is an Ant
 */
Organism::Organism(bool b) {
	amAnt = b;
	stepsTilBreed = 0;
}

/**
 * Whether or not the Organism is an Ant
 * @return true if the Organism is an Ant
 *         false if the Organism is not an Ant
 */
bool Organism::isPrey() {
	return amAnt;
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
 * Destructor for an Organism
 * Removes the Organism from the Grid and memory
 */
Organism::~Organism() {

}

