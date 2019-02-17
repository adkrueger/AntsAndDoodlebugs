/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

class Doodlebug: public Organism {
private:
	int r = 0;
	int c = 0;
	int movesWithoutBreeding = 0;
public:
	Doodlebug();
	bool move();
	bool breed();
	bool eat();
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
