/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Grid.h"


class Ant: public Organism {
public:
	Ant();
	Ant(int r, int c, Grid* grid);
	bool move(Grid* grid);
	bool breed(Grid* grid);
	void step(Grid* grid);
	 ~Ant();
};

#endif /* ANT_H_ */
