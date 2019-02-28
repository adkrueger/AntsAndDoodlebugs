/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Production.h"
#include "Grid.h"
#include <cstdlib>
#include <iostream>

Production::Production(int argc, const char* argv[]) {
	char* ptr; // a pointer we will use to store the input
	long gs_l = strtol(argv[1],&ptr,10); // get the size of the array
	n = (int)gs_l;

	long nd_l = strtol(argv[2],&ptr,10); // get the desired sort method
	numDoodlebugs = (int)nd_l;

	long na_l = strtol(argv[3],&ptr,10); // get the desired sort method
	numAnts = (int)na_l;

	long nts_l = strtol(argv[4],&ptr,10); // get the desired sort method
	numTimeSteps = (int)nts_l;

	long seed_l = strtol(argv[5],&ptr,10); // get the desired sort method
	seed = (int)seed_l;

	long p_l = strtol(argv[6],&ptr,10); // get the desired sort method
	pause = (int)p_l;
}

bool Production::runProduction(int nSquaresOnASide, int numDoodles, int numAnts, int numTimeSteps, int seed, int pause) {
	bool result = true;
	Grid* grid = new Grid(nSquaresOnASide, numDoodles, numAnts, numTimeSteps, seed, pause);
	int r = 0;
	int c = 0;
	int numSteps = 0;
	grid->randomizeGrid();

	while(numTimeSteps-- > 0)
	{
		std::cout << "Number of ants: " << grid->numAnts << std::endl;
		std::cout << "Number of doodlebugs: " << grid->numAnts << std::endl;

		c++;
		if(c >= n) {
			r++;
			c = 0;
			if(r >= n) {
				if(pause > 0) {
					grid->printGrid();
					std::cout << "Press any button to continue." << std::endl;
					std::cin.get();
				}
				r = 0;
			}
		}
		grid->step(r, c);
		numSteps++;
	}

	std::cout << "Original command line: " << nSquaresOnASide << " " << numDoodles << " " << numAnts << " " << numTimeSteps << " " << seed << " " << pause << std::endl;
	std::cout << "Number of ants at end: " << grid->numAnts << std::endl;
	std::cout << "Number of doodlebugs at end: " << grid->numDoodlebugs << std::endl;
	std::cout << "Number of steps taken: " << numSteps << std::endl;
    std::cout << "The final grid:" << std::endl;
    grid->printGrid();

	return result;
}

/**
 * Returns the variable n
 * @return the variable n
 */
int Production::getN() {
	return n;
}
/**
 * Returns the variable numDoodlebugs
 * @return the variable numDoodlebugs
 */
int Production::getNumDoodlebugs() {
	return numDoodlebugs;
}
/**
 * Returns the variable numAnts
 * @return the variable numAnts
 */
int Production::getNumAnts() {
	return numAnts;
}
/**
 * Returns the variable numTimeSteps
 * @return the variable numTimeSteps
 */
int Production::getNumTimeSteps() {
	return numTimeSteps;
}
/**
 * Returns the variable seed
 * @return the variable seed
 */
int Production::getSeed() {
	return seed;
}
/**
 * Returns the variable pause
 * @return the variable pause
 */
int Production::getPause() {
	return pause;
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

