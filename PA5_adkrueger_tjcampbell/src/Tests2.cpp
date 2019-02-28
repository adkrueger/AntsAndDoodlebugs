/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>

/**
 * Calls a constructor to create a test object that allows us to run tests
 */
Tests2::Tests2() {
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

	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok12 && ok13 && ok14 && ok15;
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

	myGrid.printGrid();
	puts("(The default grid of size 20, which is completely empty except for an Ant)");
	delete ant;
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

	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	if(myGrid_p->getCellOccupant(1, 2)!= nullptr)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	puts("The grid before an Ant is added");
	myGrid_p->printGrid();
	Ant* ant = new Ant(1, 2, myGrid_p);
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!= ant) {
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	puts("The grid after an Ant is added");
	myGrid_p->printGrid();

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
	puts("The grid before the Ant moves");
	myGrid->printGrid();
	myAnt->move(myGrid);
	if (myGrid->getCellOccupant(1,1) == nullptr) { // if the ant is not in the same location, it moved
		result = true;
	}
	puts("The grid after the Ant moves");
	myGrid->printGrid();

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
	puts("Running the ants don't move test");
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
	result = !a3->move(myGrid_p);

	puts("The grid before the Ant attempts to move");
	myGrid_p->printGrid();
	a3->move(myGrid_p);
	puts("The grid after the Ant attempts to move (the exact same)");
	myGrid_p->printGrid();
	if(myGrid_p->getCellOccupant(1, 1) != a3) {
		result = false;
	}

	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete a5;
	delete a6;
	delete a7;
	delete a8;
	delete a9;
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
	puts("The grid before the Ant breeds");
	myGrid_p->printGrid();
	a1->breed(myGrid_p);
	puts("The grid after the Ant breeds");
	myGrid_p->printGrid();
	if(myGrid_p->getCellOccupant(1, 2) == nullptr && myGrid_p->getCellOccupant(1, 0) == nullptr
			&& myGrid_p->getCellOccupant(2, 1) == nullptr && myGrid_p->getCellOccupant(0, 1) == nullptr){
		result = false;
	}

	delete a1;
	delete myGrid_p;
	return result;
}
/**
 * Tests whether or not the Ant doesn't breed when surrounded on 4 sides
 * @return true if pass, false if fail
 */
bool Tests2::antsDontBreedTest()
{
	bool result = false;
	std::cout << "Running the ants don't breed test" << std::endl;
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
	puts("The grid before the Ant attempts to breed");
	myGrid_p->printGrid();
	a1->breed(myGrid_p);
	puts("The grid after the Ant attempts to breed (the exact same)");
	myGrid_p->printGrid();

	if(myGrid_p->getCellOccupant(1, 2) == a4 && myGrid_p->getCellOccupant(1, 0)     == a2
			&& myGrid_p->getCellOccupant(2, 1) == a5 && myGrid_p->getCellOccupant(0, 1) == a7 ){
		result = true;
	}

	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete a5;
	delete a6;
	delete a7;
	delete a8;
	delete a9;
	delete myGrid_p;
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
	puts("The grid before the Ant dies");
	myGrid_p->printGrid();
	if(myGrid_p->getCellOccupant(1, 1) == a1){
		result = true;
	}
	a1->~Ant();
	puts("The grid after the Ant dies");
	myGrid_p->printGrid();
	if(myGrid_p->getCellOccupant(1, 1) == nullptr){
		result2 = true;
	}

	delete myGrid_p;
	return result && result2;
}


/**
 * Tests whether or not the Doodlebug is created properly
 * @return true if pass, false if fail
 */
bool Tests2::makeDoodlesTest()
{
	bool result = false;
	std::cout << "Running the make doodlebugs test" << std::endl;
	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	puts("The grid before the Doodlebug is constructed");
	myGrid_p->printGrid();
	Doodlebug* d1 = new Doodlebug(0,0,myGrid_p);
	puts("The grid after the Doodlebug is constructed");
	myGrid_p->printGrid();
	if(myGrid_p->getCellOccupant(0, 0) == d1){
		result = true;
	}

	delete d1;
	delete myGrid_p;
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
	Grid* myGrid = new Grid(2, 0, 0, 0, 0, 0);
	Doodlebug* d1 = new Doodlebug(1,1,myGrid);
	puts("The grid before the Doodlebug moves");
	myGrid->printGrid();
	d1->move(myGrid);
	puts("The grid after the Doodlebug moves");
	myGrid->printGrid();
	if (myGrid->getCellOccupant(1,1) != nullptr) { // if the ant is in the same location, it didn't move
		result = false;
	}

	delete d1;
	delete myGrid;
	return result;
}
/**
 * Tests whether or not the Doodlebug stays still when surrounded
 * @return true if pass, false if fail
 */
bool Tests2::doodleDontMoveTest()
{
	bool result = true;
	puts("Running the doodles don't move test");
	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	Doodlebug* d1 = new Doodlebug(0,1,myGrid_p);
	Doodlebug* d2 = new Doodlebug(1,0,myGrid_p);
	Doodlebug* d3 = new Doodlebug(1,1,myGrid_p);
	Doodlebug* d4 = new Doodlebug(1,2,myGrid_p);
	Doodlebug* d5 = new Doodlebug(2,1,myGrid_p);

	puts("The grid before the Doodlebug attempts to move");
	myGrid_p->printGrid();
	d3->move(myGrid_p);
	puts("The grid after the Doodlebug attempts to move (the exact same)");
	myGrid_p->printGrid();

	if(myGrid_p->getCellOccupant(1, 1) != d3){
		result = false;
	}

	delete d1;
	delete d2;
	delete d3;
	delete d4;
	delete d5;
	delete myGrid_p;
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
	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	Doodlebug* d1 = new Doodlebug(1,1,myGrid_p);
	puts("The grid before the Doodlebug attempts to breed");
	myGrid_p->printGrid();
	d1->breed(myGrid_p);
	puts("The grid after the Doodlebug attempts to breed");
	myGrid_p->printGrid();

	if(myGrid_p->getCellOccupant(1, 2) == nullptr && myGrid_p->getCellOccupant(1, 0)     == nullptr
			&& myGrid_p->getCellOccupant(2, 1) == nullptr && myGrid_p->getCellOccupant(0, 1) == nullptr ){
		result = false;
	}

	delete d1;
	delete myGrid_p;
	return result;
}

/**
 * Tests whether or not the Doodlebug waits to breed when surrounded
 * @return true if pass, false if fail
 */
bool Tests2::doodleDontBreedTest()
{
	puts("Running the doodle don't breed test");
	bool result = true;
	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	Doodlebug* d1 = new Doodlebug(1,1,myGrid_p);
	Doodlebug* d2 = new Doodlebug(1,0,myGrid_p);
	Doodlebug* d3 = new Doodlebug(1,1,myGrid_p);
	Doodlebug* d4 = new Doodlebug(1,2,myGrid_p);
	Doodlebug* d5 = new Doodlebug(2,1,myGrid_p);
	Doodlebug* d6 = new Doodlebug(0,2,myGrid_p);
	Doodlebug* d7 = new Doodlebug(0,1,myGrid_p);
	Doodlebug* d8 = new Doodlebug(2,2,myGrid_p);
	Doodlebug* d9 = new Doodlebug(2,0,myGrid_p);
	puts("The grid before the Doodlebug attempts to breed");
	myGrid_p->printGrid();
	d1->breed(myGrid_p);
	puts("The grid after the Doodlebug attempts to breed (the exact same)");
	myGrid_p->printGrid();

	if(myGrid_p->getCellOccupant(1, 2) == d4 && myGrid_p->getCellOccupant(1, 0) == d2
			&& myGrid_p->getCellOccupant(2, 1) == d5 && myGrid_p->getCellOccupant(0, 1) == d7 ){
		result = true;
	}

	delete d1;
	delete d2;
	delete d3;
	delete d4;
	delete d5;
	delete d6;
	delete d7;
	delete d8;
	delete d9;
	delete myGrid_p;
	return result;
}

/**
 * Tests whether or not the Doodlebug eats an Ant properly
 * @return true if pass, false if fail
 */
bool Tests2::doodleEatTest()
{
	bool result = false;
	std::cout << "Running the doodle eats ant test" << std::endl;
	Grid* myGrid_p = new Grid(2, 0, 0, 0, 0, 0);
	Doodlebug* d1 = new Doodlebug(1,1,myGrid_p);
	Ant* a1 = new Ant(0,1,myGrid_p);
	Ant* a2 = new Ant(1,0,myGrid_p);
	puts("The grid before the Ant gets eaten");
	myGrid_p->printGrid();
	a1->move(myGrid_p); // moves to (0,0)
	a2->move(myGrid_p); // doesn't move (is stuck next to doodlebug)
	d1->eat(myGrid_p,1,0);
	delete d1; // delete the doodlebug from its position to simulate how move calls eat, which then delete
	puts("The grid after the Ant gets eaten (and one of the ants moves)");
	myGrid_p->printGrid();
	if(myGrid_p->getCellOccupant(1, 1) == nullptr && myGrid_p->getCellOccupant(1, 0) == d1){
		result = true;
	}

	delete myGrid_p;
	return result;
}

/**
 * Tests whether or not the Doodlebug dies properly
 * @return true if pass, false if fail
 */
bool Tests2::doodleDietest()
{
	bool result = false;
	std::cout << "Running the doodlebug dies test" << std::endl;
	Grid* myGrid_p = new Grid(3, 0, 0, 0, 0, 0);
	Doodlebug* d1 = new Doodlebug(1,1,myGrid_p);
	puts("The grid before the Doodlebug dies");
	myGrid_p->printGrid();
	d1->~Doodlebug();
	puts("The grid after the Doodlebug dies");
	myGrid_p->printGrid();
	if(myGrid_p->getCellOccupant(1, 1) == nullptr){
		result = true;
	}

	delete myGrid_p;
	return result;
}


/**
 * Destroys the memory held by a test (none)
 */
Tests2::~Tests2() {
}

