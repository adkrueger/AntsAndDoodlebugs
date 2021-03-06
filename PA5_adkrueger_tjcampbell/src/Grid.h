/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: Aaron Krueger & Theo Campbell
 */

#ifndef GRID_H_
#define GRID_H_

#include "Organism.h"
class Organism;

class Grid {
public:
    int numAnts;
    int numDoodlebugs;
	Organism*** orgArray = (Organism***)nullptr;
	int n=0; //this initial value will be changed when the program is invoked
	Grid();
	Grid(int nSquaresOnASide, int numDoodles, int numAnts);
	void setCellOccupant(int r, int c, Organism* o);
	Organism* getCellOccupant(int r, int c);
	void step(int r, int c);
	char getLetter(int r, int c);
	void printGrid();
	void randomizeGrid(int RNG);
	virtual ~Grid();
};

#endif /* GRID_H_ */
