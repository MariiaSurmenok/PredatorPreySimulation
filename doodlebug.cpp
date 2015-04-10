/*** Implementation of class Doodlebug ***/
//File: doodlebug.cpp

#include "doodlebugH.h"
#include "antH.h"
#include <iostream>
#include <utility>
#include <ctime>

using namespace std;

Doodlebug::Doodlebug()
	: Organism()
{}

Doodlebug::Doodlebug(pair< int, int> p_pair)
	: Organism(p_pair)
{
	image = 'X';
	breedingAge = 8; // if survives, can breed after 8 steps
	starve = 0;
}

void Doodlebug::move(vector< Organism *> bugs)
{
	if (hunt(bugs))
	{
		age++;
	}
	else
	{
		starve++;
		if(starve % 3 == 0)
		{
			isAlive = false;
		}
		Organism::move(bugs);
	}
}


bool Doodlebug::hunt(vector< Organism*> &bugs) // if hunt was successful return true
{
	for(int i = 0; i < 4; i++)
	{
		pair< int, int> tempCoordinates = generateCoordinates(i);
		if(tempCoordinates.first != -1 && tempCoordinates.second != -1 &&
			tempCoordinates.first < sizeOfGrid && tempCoordinates.second < sizeOfGrid)
		{
			int index = watchingCoordinate(bugs, tempCoordinates);

			if(index != -1 && dynamic_cast<Ant *>(bugs.at(index)) != NULL)
			{
				Organism* tempOrganism = bugs.at(index);
				coordinates = (*tempOrganism).coordinates;
				(*tempOrganism).isAlive = false;
				starve = 0;
				return true;
			}
		}
	}
	return false;
}