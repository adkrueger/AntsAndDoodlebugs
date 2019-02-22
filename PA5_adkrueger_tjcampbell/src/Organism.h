/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include "Grid.h"
class Grid;

class Organism {
protected:
	int stepsTilBreed; // starts at 0, used as a counter to determine when the organism breeds
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
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
