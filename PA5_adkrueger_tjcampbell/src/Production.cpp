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

	long nd_l = strtol(argv[2],&ptr,10); // get the desired number of doodlebugs
	numDoodlebugs = (int)nd_l;

	long na_l = strtol(argv[3],&ptr,10); // get the desired number of ants
	numAnts = (int)na_l;

	long nts_l = strtol(argv[4],&ptr,10); // get the desired number of time steps
	numTimeSteps = (int)nts_l;

	long seed_l = strtol(argv[5],&ptr,10); // get the desired seed
	seed = (int)seed_l;

	long p_l = strtol(argv[6],&ptr,10); // get the desired value for pause
	pause = (int)p_l;
}

/**
 * Runs production with default values
 * (which are initialized in .h file)
 */
bool Production::runProduction() {
	return runProduction(n, numDoodlebugs, numAnts, numTimeSteps, seed, pause);
}

/**
 * Runs the production based on user input
 * @param nSquaresOnASide The dimensions of the game (n x n grid size) (default 20)
 * @param numDoodles The
 */
bool Production::runProduction(int nSquaresOnASide, int numDoodles, int numAnts, int numTimeSteps, int seed, int pause) {
	bool result = true;
	Grid* grid = new Grid(nSquaresOnASide, numDoodles, numAnts, numTimeSteps, seed, pause);
	int r = 0; // the row we will be stepping
	int c = 0; // the column we will be stepping
	int numSteps = 0; // the number of steps that have been moved through
	if(seed == 0) { // if the seed asks for the current time
		grid->randomizeGrid(time(0)); // set the seed to the current time
	}
	else
		if(seed > 0) { // if the seed was input, then use it as the number for the generator
			grid->randomizeGrid(seed); // otherwise, set the seed to that specified by the user
		}

	while(numTimeSteps-numSteps > 0 && (grid->numAnts > 0 || grid->numDoodlebugs > 0)) { // while there are timesteps remaining, as well as at least one ant or doodlebug
		c++;
		if(c >= n) { // if c is out of bounds
			r++;
			c = 0;
			if(r >= n) { // if r is out of bounds
				r = 0;
			}
		}
		grid->step(r, c); // cause the currently selected position to step
		std::cout << "Number of ants: " << grid->numAnts << std::endl;
		std::cout << "Number of doodlebugs: " << grid->numDoodlebugs << std::endl;
		if(pause > 0) { // if the user wants the program to pause
			if(numSteps % pause == 0) { // if the given number of timesteps aligns with pause input, pause
				grid->printGrid();
				std::cout << "Press enter to continue." << std::endl;
				std::cin.get();
			}
		}
		numSteps++;
	}

	// print the required values, then the grid
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

