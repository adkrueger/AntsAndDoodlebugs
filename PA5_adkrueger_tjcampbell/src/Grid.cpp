/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Aaron Krueger
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Cell.h"
#include "Organism.h"


/**
 * Creates a Grid of a default number of Cells
 */
Grid::Grid() {
	numDoodlebugs = 0;
	numAnts = 0;
	// TODO Auto-generated constructor stub
	Grid(20); //calls general constructor with default value
	numTimeSteps = 0;
	orgArray = (Organism***) malloc(n * sizeof(Organism**));
	// Each entry is a pointer to a row
	for (int i = 0; i < n; i++) {
		orgArray[i] = (Organism**) malloc(n * sizeof(Organism*)); // Each row is an array of pointers to Organisms
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
	//we do not want automatic storage for the grid

	//*orgArray = new Organism* [n];  //first allocate array of row pointers

	orgArray = (Organism***) malloc(n * sizeof(Organism**));
	// Each entry is a pointer to a row
	for (int i = 0; i < n; i++) {
		orgArray[i] = (Organism**) malloc(n * sizeof(Organism*)); // Each row is an array of pointers to Organisms
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
			if (&*orgArray[r][c] != nullptr) {
				orgArray[r][c]->move(this);
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
	char val = '0';

	if((*org).isPrey() == true) {
		return 'A';
	}
	else if((*org).isPrey() == false) {
		return 'D';
	}

	return val;
}
/**
 * Prints out the grid in a format corresponding to what is in each Cell
 * D if the organism is a Doodlebug
 * A if the organism is an Ant
 * 0 if the cell is empty
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
	//TODO: make destructor!
	//for(int r=0; r < n; r++) {
		//for(int c=0; c < n; c++) {
		//	//cout << "Before freeing" << r << c << endl;
			//(*orgArray[r][c]).~Organism(); // free memory for columns in each row
		//}
	//}
	//orgArray = (Organism***)nullptr;
}

