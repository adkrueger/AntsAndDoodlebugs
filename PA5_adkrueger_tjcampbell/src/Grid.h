/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_

#include "Cell.h"
#include "Organism.h"
#include "occupationStatus.h"
class Cell;
class Organism;

class Grid {
private:
	int numTimeSteps; // starts at 0, when it reaches the number specified by the user game ends

public:
    int numAnts;
    int numDoodlebugs;
	Organism*** orgArray = (Organism***)nullptr;
	int n=0; //this initial value will be changed when the program is invoked
	Grid();
	Grid(int nSquaresOnASide);
	void setCellOccupant(int r, int c, Organism* o);
	Organism* getCellOccupant(int r, int c);
	void step();
	char getLetter(int r, int c);
	void printGrid();
	virtual ~Grid();
};

#endif /* GRID_H_ */
