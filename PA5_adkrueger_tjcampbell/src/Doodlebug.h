/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Grid.h"
#include "Organism.h"

class Doodlebug: public Organism {
protected:
	int r;
	int c;
	int stepsTilStarve;
	int movesWithoutBreeding;
	Grid* grid;
public:
	Doodlebug();
	Doodlebug(int r, int c, Grid* grid);
	bool move(Grid* grid);
	bool breed(Grid* grid);
	bool eat(Grid* grid);
	void step(Grid* grid);
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
