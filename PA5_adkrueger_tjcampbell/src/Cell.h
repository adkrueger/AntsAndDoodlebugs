/*
 * Cell.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef CELL_H_
#define CELL_H_
#include "Organism.h"
#include "occupationStatus.h"
class Organism;

class Cell {
protected:
	int r;
	int c;
public:
	Cell();
	Cell(int r, int c);
	bool setOccupant(occupationStatus g);
	Organism* setOrganism(occupationStatus g);
	occupationStatus getOccupant();
	Organism* getOrganism(Cell c);
	void deleteOccupant(int r, int c);
	virtual ~Cell();
};

#endif /* CELL_H_ */
