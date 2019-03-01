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
#include "Doodlebug.h"
#include "Ant.h"


/**
 * Creates a Grid of a default number of Cells
 */
Grid::Grid() {
	numDoodlebugs = 5; // the default number of doodlebugs on the board
	numAnts = 100; // the default number of ants on the board
	n = 20; // the default size of the board
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
Grid::Grid(int nSquaresOnASide, int numDoodlebugs, int numAnts) {
	this->numDoodlebugs = numDoodlebugs; // the number of doodlebugs on the board
	this->numAnts = numAnts; // the number of ants on the board
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
void Grid::step(int r, int c) {
	if (orgArray[r][c] != nullptr) { // if the space isn't empty
		getCellOccupant(r,c)->step(this); // then cause the Organism to take a step
	}
}

/**
 * Returns a letter corresponding to the type of Organism in a certain Cell
 * @return a letter that corresponds to the type of Organism in a certain Cell
 */
char Grid::getLetter(int r, int c) {
	Organism* org = orgArray[r][c];
	char val = ' '; // a blank space

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
	for(int r = 0; r < n; r++) { // for each row
		for(int c = 0; c < n; c++) { // and for each col
			std::cout << getLetter(r, c); // print the letter
		}
		std::cout << std::endl;
	}
}

/**
 * Fills orgArray with random Organisms based on the number of each count
 */
void Grid::randomizeGrid(int RNG) {
	srand(RNG); // set the seed to whatever the user desires
    int doodleCount = numDoodlebugs; // a placeholder for the number of doodles, will be decremented as more are added
    int antCount = numAnts; // a placeholder for the number of doodles, will be decremented as more are added
    int randRow; // a random row, which will decide where the organism belongs
    int randCol; // a random col, which will decide where the organism belongs

    while(doodleCount > 0 || antCount > 0) {
    	randRow = (int)(rand() % n); // initializing the row to be within bounds
    	randCol = (int)(rand() % n); // initializing the col to be within bounds
    	if(doodleCount && getCellOccupant(randRow, randCol) == nullptr){ // if there are remaining doodlebugs to place, as well as remaining empty spots
    	    setCellOccupant(randRow, randCol, new Doodlebug(randRow, randCol, this));
    	    doodleCount--; // decrement the number of doodles left to place
    	}
    	if(antCount && getCellOccupant(randRow, randCol) == nullptr) { // if there are remaining ants to place, and a space is empty
    	    setCellOccupant(randRow, randCol, new Ant(randRow, randCol, this));
    	    antCount--; // decrement the number of ants left to place
    	}
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

