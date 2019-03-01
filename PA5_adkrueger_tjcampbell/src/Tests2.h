/*
 * Tests2.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Aaron Krueger & Theo Campbell
 */

#ifndef TESTS2_H_
#define TESTS2_H_

class Tests2 {
public:
	Tests2();
	bool doTests();
	bool gridTest();
	bool makeAntsTest();
	bool antsMoveTest();
	bool antsDontMoveTest();
	bool antsBreedTest();
	bool antsDontBreedTest();
	bool antsDieTest();
	bool makeDoodlesTest();
	bool doodleMoveTest();
	bool doodleDontMoveTest();
	bool doodleBreedTest();
	bool doodleDontBreedTest();
	bool doodleEatTest();
	bool doodleRandomlyEatTest();
	bool doodleDietest();
    bool deleteOccupantTest();


	virtual ~Tests2();
};

#endif /* TESTS2_H_ */
