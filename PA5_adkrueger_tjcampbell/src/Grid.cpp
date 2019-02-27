/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Aaron Krueger
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Organism.h"


/**
 * Creates a Grid of a default number of Cells
 */
Grid::Grid() {
	numDoodlebugs = 0;
	numAnts = 0;
	Grid(20); //calls general constructor with default value
	numTimeSteps = 0;
	orgArray = new Organism**[n]; // the array is an array of n arrays, each of which contains n pointers to organisms
	for (int i = 0; i < n; i++) {
		orgArray[i] = new Organism*[n]; // Each row is an array of pointers to Organisms
		for(int j = 0; j < n; j++) {
			orgArray[i][j] = nullptr; // each organism initially points to nullptr (empty)
		}
	}
}

/**
 * Creates a Grid with a given number of Cells on each side
 * @param nSquaresOnASide The amount of squares on each side of the board
 */
Grid::Grid(int nSquaresOnASide) {
	numDoodlebugs = 0;
	numAnts = 0;
	numTimeSteps = 0;
	n = nSquaresOnASide; //initialize size of grid
	orgArray = new Organism**[n]; // the array is an array of n arrays, each of which contains n pointers to organisms
	for (int i = 0; i < n; i++) {
		orgArray[i] = new Organism*[n]; // Each row is an array of pointers to Organisms
		for(int j = 0; j < n; j++) {
			orgArray[i][j] = nullptr; // each organism initially points to nullptr (empty)
		}
	}
}

/**
 * Sets the occupant of the cell to the given values.
 * @param r The row of the occupant
 * @param c The column of the occupant
 * @param g The new occupant
 */
void Grid::setCellOccupant(int r, int c, Organism* o) {
	orgArray[r][c] = o;
}

/**
 * Returns the occupant of a given Cell.
 * Will not check if r and c are within bounds!
 * @param r the row of the given Cell
 * @param c the column of the given Cell
 * @return A pointer to the organism in the cell
 */
Organism* Grid::getCellOccupant(int r, int c) {
	return orgArray[r][c];
}

/**
 * Takes one "step" through the game.
 */
void Grid::step() {
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			if (orgArray[r][c] != nullptr) { // if the space isn't empty
				orgArray[r][c]->step(this); // then cause the Organism to take a step
			}
		}
	}
}

/**
 * Returns a letter corresponding to the type of Organism in a certain Cell
 * @return a letter that corresponds to the type of Organism in a certain Cell
 */
char Grid::getLetter(int r, int c) {
	Organism* org = orgArray[r][c];
	char val = ' ';

	if((*org).isPrey() == true && org != nullptr) { // if the organism is an Ant (and not an empty space, which are initialized with amAnt = true)
		return 'o';
	}
	else if((*org).isPrey() == false) { // if the organism is a Doodlebug
		return 'x';
	}

	return val;
}
/**
 * Prints out the grid in a format corresponding to what is in each Cell
 * x if the organism is a Doodlebug
 * o if the organism is an Ant
 * ' ' (empty space) if the cell is empty
 * @param grid The grid to be printed
 * @param r The number of rows in the grid
 * @param c The number of columns in the grid
 */
void Grid::printGrid() {
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			std::cout << getLetter(r, c);
		}
		std::cout << std::endl;
	}
}


/**
 * Destroys the given Grid, going row by row and removing each Cell from memory
 */
Grid::~Grid() {
	for(int r=0; r < n; r++) {
		delete[] orgArray[r];
	}
	orgArray = (Organism***)nullptr;
}

