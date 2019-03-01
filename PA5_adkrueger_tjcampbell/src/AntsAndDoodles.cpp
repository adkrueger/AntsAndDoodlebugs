//============================================================================
// Name        : Ants.cpp
// Author      : Aaron Krueger & Theo Campbell
// Version     : 2/28/19
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Tests2.h"
#include "Production.h"
class Tests;
class Production;

/** The production constructor of the program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line
 * @return 0 if success
 */
int main(int argc, const char* argv[])
{//gridSize #doodlebugs #ants #time_steps seed pause
	std::cout << "!!!Hello the classmates, it's time for fun with C++!!!" << std::endl;
    Tests2 ts = Tests2(); // create a tests object
    if(ts.doTests()) // run the tests
	{
		Production ps = Production(argc, argv); // create a production object
		bool ok = ps.runProduction(ps.getN(), ps.getNumDoodlebugs(), ps.getNumAnts(), ps.getNumTimeSteps(), ps.getSeed(), ps.getPause()); // run production
		if(ok) // if production worked
		{
			puts("Production worked.");
		}
		else
		{
			puts("Production did not work.");
		}
		ps.~Production(); //done with production
	}
    ts.~Tests2(); //done with tests

	return 0;
}
