/*** Implementation class Ant ***/
//File: ant.cpp

#include "antH.h"
#include <iostream>
#include <utility>
using namespace std;

Ant::Ant(pair< int, int> p_pair)
	:Organism(p_pair)
{
	image = 'O';
	breedingAge = 3; // if survives, can breed after 3 steps
}