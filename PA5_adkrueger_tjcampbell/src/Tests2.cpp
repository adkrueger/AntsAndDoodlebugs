/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include <iostream>


Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

/**
 * Runs all of the tests
 * @return true if they all pass, false if any one fails
 */
bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	//populate it with ants
	bool ok2 = makeAntsTest();
	//see whether they move
	bool ok3 = antsMoveTest();
	//see whether they breed
	bool ok4 = antsBreedTest();
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	//see whether they move
	bool ok7 = doodleMoveTest();
	//see whether they breed
	bool ok8 = doodleBreedTest();
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	//see whether they die
	bool ok10 = doodleDietest();
	//see whether we can delete occupants
	bool ok11 = deleteOccupantTest();
	// see whether the ants don't move when surrounded
	bool ok12 = antsDontMoveTest();
	// see whether the ants wait to breed when surrounded
	bool ok13 = antsDontBreedTest();
    // see whether the doodlebugs don't move when surrounded
	bool ok14 = doodleDontMoveTest();
	// see whether the doodlebugs wait to breed when surrounded
	bool ok15 = doodleDontBreedTest();
    // see whether the doodlebugs eat ants randomly
	bool ok16 = doodleRandomlyEatTest();

	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12 && ok13 && ok14 && ok15 && ok16;
	return results;
}

/**
 * Tests whether or not the grid is created properly
 * @return true if pass, false if fail
 */
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;

	std::cout << "Running the grid test" << std::endl;
	Grid myGrid = Grid(8);
	if(myGrid.getCellOccupant(2, 3) != nullptr)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	//std::cout << "second grid test" << std::endl;
	Ant* ant = new Ant(2, 3, &myGrid);
	myGrid.setCellOccupant(2, 3, ant);
	if(myGrid.getCellOccupant(2, 3) != ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	//std::cout << "third grid test" << std::endl;
   // delete(&myGrid);
	result = ok1 && ok2;
	return result;
}

/**
 * Tests whether or not the grid is created properly
 * @return true if pass, false if fail
 */
bool Tests2::makeAntsTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
/*
	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!= occupationStatus::empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, occupationStatus::ant);
	if(myGrid_p->getCellOccupant(1, 2)!= occupationStatus::ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant(3,4);
	if(myGrid_p->getCellOccupant(3, 4)!= occupationStatus::empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, occupationStatus::doodlebug);
	if(myGrid_p->getCellOccupant(3, 4)!= occupationStatus::doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, occupationStatus::empty);
	delete a1;
	delete myGrid_p;
*/
	result = ok1 && ok2;
	return result;
}

/**
 * Tests whether or not the Ants move at all
 * @return true if pass, false if fail
 */
bool Tests2::antsMoveTest() {
	bool result = true;
	std::cout << "Running the move ants test" << std::endl;
/*
	Grid* myGrid = new Grid(2);
    Ant* myAnt = new Ant(1,1);
    myAnt->move();
    if (myGrid->getCellOccupant(1,1) != empty) { // if the ant is in the same location, it didn't move
    	result = false;
    }

    delete myAnt;
    delete myGrid;
*/
	return result;
}

/**
 * Tests the ant's movement if it is blocked on all sides
 * @return true if the ant stays in the same spot, false otherwise
 */
bool Tests2::antsDontMoveTest() {
	bool result = true;

	return result;
}

/**
 * Tests whether or not the Ant breeds properly
 * @return true if pass, false if fail
 */
bool Tests2::antsBreedTest()
{
	bool result = true;
	std::cout << "Running the breed ants test" << std::endl;
	return result;
}

/**
 * Tests whether or not the Ant doesn't breed when surrounded on 4 sides
 * @return true if pass, false if fail
 */
bool Tests2::antsDontBreedTest()
{
	bool result = true;

	return result;
}

/**
 * Tests whether or not the Ant dies
 * @return true if pass, false if fail
 */
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	return result;
}

/**
 * Tests whether or not the Doodlebug is created properly
 * @return true if pass, false if fail
 */
bool Tests2::makeDoodlesTest()
{
	bool result = true;
	std::cout << "Running the make doodlebugs test" << std::endl;
	return result;
}

/**
 * Tests whether or not the Doodlebug moves properly
 * @return true if pass, false if fail
 */
bool Tests2::doodleMoveTest()
{
	bool result = true;
	std::cout << "Running the move doodlebugs test" << std::endl;
	return result;
}

/**
 * Tests whether or not the Doodlebug stays still when surrounded
 * @return true if pass, false if fail
 */
bool Tests2::doodleDontMoveTest()
{
	bool result = true;

	return result;
}

/**
 * Tests whether or not the Doodlebug breeds properly
 * @return true if pass, false if fail
 */
bool Tests2::doodleBreedTest()
{
	bool result = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;
	return result;
}

/**
 * Tests whether or not the Doodlebug waits to breed when surrounded
 * @return true if pass, false if fail
 */
bool Tests2::doodleDontBreedTest()
{
	bool result = true;

	return result;
}

/**
 * Tests whether or not the Doodlebug eats an Ant properly
 * @return true if pass, false if fail
 */
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	return result;
}

/**
 * Tests whether or not the Doodlebug eats ants randomly
 * @return true if pass, false if fail
 */
bool Tests2::doodleRandomlyEatTest()
{
	bool result = true;

	return result;
}

/**
 * Tests whether or not the Doodlebug dies properly
 * @return true if pass, false if fail
 */
bool Tests2::doodleDietest()
{
	bool result = true;
	std::cout << "Running the doodlebug dies test" << std::endl;
	return result;
}

/**
 * Tests whether or not we can delete the occupant of a cell
 * @return true if the occupant is deleted, false otherwise
 */
bool Tests2::deleteOccupantTest() {
	bool result = true;

	return result;
}

/**
 * Destroys the memory held by a test
 */
Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

