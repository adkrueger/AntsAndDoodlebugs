/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Aaron Krueger & Theo Campbell
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include "Grid.h"
class Grid;

class Organism {
protected:
	bool amAnt = true;
	int r;
	int c;
	int movesWithoutBreeding;
	Grid* grid;
public:
	Organism();
	Organism(bool b);
	bool isPrey();
	virtual bool move(Grid* grid) = 0;
	virtual bool breed(Grid* grid) = 0;
	virtual void step(Grid* grid) = 0;
	bool checkEmptySpaces(Grid* grid, int r, int c);
	bool isEmpty(Grid* grid, int r, int c);
	void setAmAnt(bool b);
	bool canMoveHere(int direction, Grid* g, int r, int c);
	bool doodleCanMoveHere(int direction, Grid* g, int r, int c);
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
