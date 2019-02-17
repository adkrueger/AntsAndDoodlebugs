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

int n=0; //this initial value will be changed when the program is invoked
Cell** myGridCells_ptr_array = (Cell**)nullptr;

/**
 * Creates a Grid of a default number of Cells
 */
Grid::Grid() {
	// TODO Auto-generated constructor stub
	Grid(10); //calls general constructor with default value
}

/**
 * Creates a Grid with a given number of Cells on each side
 * @param nSquaresOnASide The amount of squares on each side of the board
 */
Grid::Grid(int nSquaresOnASide) {
	n = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	myGridCells_ptr_array = new Cell* [n];  //first allocate array of row pointers

	for(int i=0 ; i < n ; i++) {
		myGridCells_ptr_array[i] = new Cell[n]; // allocate memory for columns in each row
	}
}

/**
 * Sets the occupant of the cell to the given values.
 * @param r The row of the occupant
 * @param c The column of the occupant
 * @param g The occupant's type and whether or not its Cell is occupied
 * @return Whether or not the Cell has been occupied successfully
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g) {
	return myGridCells_ptr_array[r][c].setOccupant(g);
}

/**
 * Returns the occupant of a given Cell
 * @param r the row of the given Cell
 * @param c the column of the given Cell
 * @return true if something is occupying the Cell, and what that occupant may be
 *         false otherwise
 */
occupationStatus Grid::getCellOccupant(int r, int c) {
	return myGridCells_ptr_array[r][c].getOccupant();
}

/**
 * Destroys the given Grid, going row by row and removing each Cell from memory
 */
Grid::~Grid() {

	for(int r=0; r < n; r++) {
		for(int c=0; c < n; c++) {
			//cout << "Before freeing" << r << c << endl;
			myGridCells_ptr_array[r][c].~Cell(); // free memory for columns in each row
		}
	}
	//myGridCells_ptr_array = (Cell**)nullptr;
}

