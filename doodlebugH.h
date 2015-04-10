/*** Header Doodlebug class ***/
/*
File: doodlebugH.h

Constructors:

	Doodlebug();
		invoke base constructor

	Doodlebug(pair< int, int> p_pair);
		assign image = 'X'; breedingAge = 8; and starve = 0;
		invoke base constructor

Functions:

	virtual void move(vector< Organism*> bugs);
		invokes helper function hunt. If hunt wasn't successful, increases starve by one
		if starve equal 3 change isAlive to false 
		else (hunt unsuccessful) invoke function move from base class
		use vector< Organism*> for pass it in hunt function

Helper functions:

	bool hunt(vector< Organism*> &bugs);
		search ant around. If function find ant, for this ant isAlife = false, 
		change the doodlebug coordinates to the ant's and starve = 0
		return true if hunt was successful

Variables:
	starve
		accumulate how long doodlebug is starving
*/

#ifndef DOODLEBUG_MARIIALAB
#define DOODLEBUG_MARIIALAB

#include "organismH.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Doodlebug : public Organism
{
public:
	//Constructors
	Doodlebug();
	Doodlebug(pair< int, int> p_pair);

	virtual void move(vector< Organism*> bugs);

	//If hunt was successful, return true
	bool hunt(vector< Organism*> &bugs);
	bool eatAnts(vector< Organism*> bugs, int direction);

private:
	int starve;
};

#endif;