/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Aaron Krueger & Theo Campbell
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Grid.h"
#include "Organism.h"

class Doodlebug: public Organism {
protected:
	int stepsTilStarve;
public:
	Doodlebug();
	Doodlebug(int r, int c, Grid* grid);
	bool move(Grid* grid);
	bool breed(Grid* grid);
	bool eat(Grid* grid, int r, int c);
	void step(Grid* grid);
	bool starve();
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
