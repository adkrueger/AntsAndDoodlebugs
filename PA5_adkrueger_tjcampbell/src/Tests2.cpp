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
	if (ok1){
		std::cout << "GridTest() Passed" << std::endl << std::endl;
	}
	//populate it with ants
	bool ok2 = makeAntsTest();
	if (ok2){
		std::cout << "makeAntsTest() Passed" << std::endl << std::endl;
	}
	//see whether they move
	bool ok3 = antsMoveTest();
	if (ok3){
		std::cout << "antsMoveTest() Passed" << std::endl << std::endl;
	}
	//see whether they breed
	bool ok4 = antsBreedTest();
	if (ok4){
		std::cout << "antsBreedTest() Passed" << std::endl << std::endl;
	}
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	if (ok5){
		std::cout << "antsDieTest() Passed" << std::endl << std::endl;
	}
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	if (ok6){
		std::cout << "makeDoodlesTest() Passed" << std::endl << std::endl;
	}
	//see whether they move
	bool ok7 = doodleMoveTest();
	if (ok7){
		std::cout << "doodleMoveTest() Passed" << std::endl << std::endl;
	}
	//see whether they breed
	bool ok8 = doodleBreedTest();
	if (ok8){
		std::cout << "doodleBreedTest() Passed" << std::endl << std::endl;
	}
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	if (ok9){
		std::cout << "doodleEatTest() Passed" << std::endl << std::endl;
	}
	//see whether they die
	bool ok10 = doodleDietest();
	if (ok10){
		std::cout << "doodleDieTest() Passed" << std::endl << std::endl;
	}
	//see whether we can delete occupants
	bool ok11 = deleteOccupantTest();
	if (ok11){
		std::cout << "deleteOccupantTest() Passed" << std::endl << std::endl;
	}
	// see whether the ants don't move when surrounded
	bool ok12 = antsDontMoveTest();
	if (ok12){
		std::cout << "antsDontMoveTest() Passed" << std::endl << std::endl;
	}
	// see whether the ants wait to breed when surrounded
	bool ok13 = antsDontBreedTest();
	if (ok13){
		std::cout << "antsDontBreedTest() Passed" << std::endl << std::endl;
	}
	// see whether the doodlebugs don't move when surrounded
	bool ok14 = doodleDontMoveTest();
	if (ok14){
		std::cout << "doodleDontMoveTest() Passed" << std::endl << std::endl;
	}
	// see whether the doodlebugs wait to breed when surrounded
	bool ok15 = doodleDontBreedTest();
	if (ok15){
		std::cout << "doodleDontBreedTest() Passed" << std::endl << std::endl;
	}
	// see whether the doodlebugs eat ants randomly
	bool ok16 = doodleRandomlyEatTest();
	if (ok16){
		std::cout << "doodleRandomlyEatTest() Passed" << std::endl << std::endl;
	}

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
	Grid myGrid = Grid();
	if(myGrid.getCellOccupant(2, 3) != nullptr)	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	//std::cout << "second grid test" << std::endl;
	Ant* ant = new Ant(2, 3, &myGrid);
	myGrid.setCellOccupant(2, 3, ant);
	if(myGrid.getCellOccupant(2, 3) != ant) {
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	//std::cout << "third grid test" << std::endl;
	result = ok1 && ok2;
	return result;
}

/**
 * Tests whether or not the grid is created properly
 * @return true if pass, false if fail
 */
bool Tests2::makeAntsTest() {
	bool result = true;
	bool ok1 = true;

	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9, 0, 0, 0, 0, 0);
	if(myGrid_p->getCellOccupant(1, 2)!= nullptr)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	Ant* ant = new Ant(1, 2, myGrid_p);
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!= ant) {
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}

	delete ant;
	delete myGrid_p;

	result = ok1;
	return result;
}

/**
 * Tests whether or not the Ants move at all
 * @return true if pass, false if fail
 */
bool Tests2::antsMoveTest() {
	bool result = false;
	std::cout << "Running the move ants test" << std::endl;

	Grid* myGrid = new Grid(2, 0, 0, 0, 0, 0);
	Ant* myAnt = new Ant(1,1,myGrid);
	myAnt->move(myGrid);
	if (myGrid->getCellOccupant(1,1) == nullptr) { // if the ant is not in the same location, it moved
		result = true;
	}

	delete myAnt;
	delete myGrid;

	return result;
}

/**
 * Tests the ant's movement if it is blocked on all sides
 * @return true if the ant stays in the same spot, false otherwise
 */
bool Tests2::antsDontMoveTest() {
	bool result = true;

	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	Ant* a1 = new Ant(0,1,myGrid_p);
	Ant* a2 = new Ant(1,0,myGrid_p);
	Ant* a3 = new Ant(1,1,myGrid_p);
	Ant* a4 = new Ant(1,2,myGrid_p);
	Ant* a5 = new Ant(2,1,myGrid_p);
	Ant* a6 = new Ant(0,2,myGrid_p);
	Ant* a7 = new Ant(0,1,myGrid_p);
	Ant* a8 = new Ant(2,2,myGrid_p);
	Ant* a9 = new Ant(2,0,myGrid_p);
	result = a3->move(myGrid_p);

	a3->move(myGrid_p);
	if(myGrid_p->getCellOccupant(1, 1) != a3) {
		result = false;
	}


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
	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	Ant* a1 = new Ant(1,1,myGrid_p);
	a1->breed(myGrid_p);

	if(myGrid_p->getCellOccupant(1, 2) == nullptr && myGrid_p->getCellOccupant(1, 0) == nullptr
			&& myGrid_p->getCellOccupant(2, 1) == nullptr && myGrid_p->getCellOccupant(0, 1) == nullptr){
		result = false;
	}

	return result;
}
/**
 * Tests whether or not the Ant doesn't breed when surrounded on 4 sides
 * @return true if pass, false if fail
 */
bool Tests2::antsDontBreedTest()
{
	bool result = false;
	std::cout << "Running the breed ants test" << std::endl;
	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	Ant* a1 = new Ant(1,1,myGrid_p);
	Ant* a2 = new Ant(1,0,myGrid_p);
	Ant* a3 = new Ant(1,1,myGrid_p);
	Ant* a4 = new Ant(1,2,myGrid_p);
	Ant* a5 = new Ant(2,1,myGrid_p);
	Ant* a6 = new Ant(0,2,myGrid_p);
	Ant* a7 = new Ant(0,1,myGrid_p);
	Ant* a8 = new Ant(2,2,myGrid_p);
	Ant* a9 = new Ant(2,0,myGrid_p);
	a1->breed(myGrid_p);

	if(myGrid_p->getCellOccupant(1, 2) == a4 && myGrid_p->getCellOccupant(1, 0)     == a2
			&& myGrid_p->getCellOccupant(2, 1) == a5 && myGrid_p->getCellOccupant(0, 1) == a7 ){
		result = true;
	}

	return result;
}
/**
 * Tests whether or not the Ant dies
 * @return true if pass, false if fail
 */
bool Tests2::antsDieTest()
{
	bool result = false;
	bool result2 = false;
	std::cout << "Running the ants die test" << std::endl;
	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	Ant* a1 = new Ant(1,1,myGrid_p);
	if(myGrid_p->getCellOccupant(1, 1) == a1){
		result = true;
	}
	a1->~Ant();
	if(myGrid_p->getCellOccupant(1, 1) == nullptr){
		result2 = true;
	}

	return result && result2;
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

