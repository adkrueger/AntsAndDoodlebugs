/*
 * Production.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

class Production {
private:
	int n = 20;
	int numDoodlebugs = 5;
	int numAnts = 100;
	int numTimeSteps = 1000;
	int seed = 1;
	int pause = 0;
public:
	Production(int argc, const char* argv[]);
	bool runProduction(int nSquaresOnASide, int numDoodles, int numAnts, int numTimeSteps, int seed, int pause);
	int getN();
	int getNumDoodlebugs();
	int getNumAnts();
	int getNumTimeSteps();
	int getSeed();
	int getPause();
	virtual ~Production();
};

#endif /* PRODUCTION_H_ */
