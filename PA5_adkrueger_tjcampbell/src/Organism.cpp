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
	// TODO Auto-generated constructor stub

}

/**
 * Constructor for an Organism, which may or may not be an Ant
 * @param b Whether or not the Organism is an Ant
 */
Organism::Organism(bool b) {
	amAnt = b;

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
 * Destructor for an Organism
 * Removes the Organism from the Grid and memory
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

