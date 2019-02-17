/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include "Cell.h"

occupationStatus guest  = empty;

/**
 * Default constructor for a cell, which automatically assumes there is
 * nothing occupying it.
 */
Cell::Cell() {

	guest = empty;
}

/**
 * Sets the occupant of a cell to a given guest, but only if the cell
 * is empty.
 * @param g The guest to be placed in the cell
 * @return true if the guest took occupancy in the cell
 *         false if the cell was already occupied and the guest took no occupancy
 */
bool Cell::setOccupant(occupationStatus g) {
	bool result = true;
	if(guest==empty) {
		guest = g;
	}
	else {
		result = false;
	}
	return result;
}

/**
 * Returns the occupant of a cell
 * @return the occupant of a cell
 */
occupationStatus Cell::getOccupant() {
	return guest;
}

/**
 * Deletes the current occupant of a given cell
 * @param r The row of the occupant
 * @param c The column of the occupant
 */
void Cell::deleteOccupant(int r, int c) {

}

/**
 * Destructor for Cell objects
 * Clears memory formerly held by an Cell
 */
Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

