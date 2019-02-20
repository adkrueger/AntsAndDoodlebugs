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
private:
	int row;
	int col;
    int movesWithoutBreeding; // incremented, after 3 steps will attempt to breed
    Grid* grid;
public:
	Ant();
	Ant(int r, int c, Grid* grid);
	bool move(Grid* grid);
	bool breed(Grid* grid);
	 ~Ant();
};

#endif /* ANT_H_ */
