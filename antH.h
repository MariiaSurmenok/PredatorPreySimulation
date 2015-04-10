/*** Header Ant class***/
//use all functions and variables from base class
//constructor assign image 'O' and breedingAge = 3

#ifndef ANT_MARIIALAB
#define ANT_MARIIALAB

#include "organismH.h"
#include <iostream>
#include <utility>
using namespace std;

class Ant:public Organism
{
	public:
	Ant(pair< int, int> p_pair);
};

#endif;