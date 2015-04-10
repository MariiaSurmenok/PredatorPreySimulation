/*** Implementation of class Organism ***/
//File: organism.cpp

#include <iostream>
#include <vector>
#include <utility>
#include <ctime>
#include "organismH.h"
#include "antH.h"
#include "doodlebugH.h"
using namespace std;

Organism::Organism()
{
	coordinates.first = 0;
	coordinates.second = 0;
	age = 0;
	image = ' ';
	isAlive = true;
	sizeOfGrid = 20;
}

Organism::Organism(pair< int, int> p_pair)
{
	age = 0;
	coordinates = p_pair;
	isAlive = true;
	sizeOfGrid = 20;
}

Organism* Organism::breed(vector< Organism*> bugs)
{
	if(age % breedingAge == 0 && isAlive)
	{
		for(int i = 0; i < 4; i++) //Try all directions
		{
			pair< int, int> tempCoordinates = generateCoordinates(i);
			if(tempCoordinates.first != -1 && watchingCoordinate(bugs, tempCoordinates) == -1)
			{
				if(dynamic_cast<Ant *>(this) != NULL) //Check is organism an Ant
				{
					Ant* newborn = new Ant(tempCoordinates);
					return newborn;
				}
				else if(dynamic_cast<Doodlebug *>(this) != NULL) //Check is organism a Doodlebug
				{
					Doodlebug* newborn = new Doodlebug(tempCoordinates);
					return newborn;
				}
			}
		}

		return NULL;
	}
	else
	{
		return NULL;
	}
}


void Organism::move(vector< Organism*> bugs)
{
	//generate random moving direction from 0 to 3
	int direction = rand() % 4; //0 - up, 1 - down, 2 - left, 3 - right

	pair< int, int> tempCoordinates = generateCoordinates(direction);

	//check that coordinates inside grid and cell is available
	if(isAlive && tempCoordinates.first != -1  && watchingCoordinate(bugs, tempCoordinates) == -1)
	{	
		coordinates = tempCoordinates;
	}

	age++;
}

//calculate new coordinates for moving and breeding 
pair< int, int> Organism::generateCoordinates(int direction) 
{
	pair< int, int> tempCoordinates(coordinates.first, coordinates.second); 

	switch (direction)
	{
	case 0: tempCoordinates.second = tempCoordinates.second - 1; // up
		break;
	case 1: tempCoordinates.second = tempCoordinates.second + 1; // down
		break;
	case 2: tempCoordinates.first = tempCoordinates.first - 1; // left
		break;
	case 3: tempCoordinates.first = tempCoordinates.first + 1; // left
		break;
	}
	if(tempCoordinates.first != -1 &&  tempCoordinates.first < sizeOfGrid
		&& tempCoordinates.second != -1 &&  tempCoordinates.second < sizeOfGrid)
	{
		return tempCoordinates;
	}
	else return pair<int, int>(-1, -1);
}

int Organism::watchingCoordinate(vector< Organism*> bugs, pair< int, int> tempC) //Check is cell available or not
{
	//if some bug is here return its index; otherwise return -1
	vector< Organism*>::iterator iter;
	int index = 0;
	for(iter = bugs.begin(); iter != bugs.end(); iter++)
	{
		if((*(*iter)).coordinates == tempC) return index;
		else index++;
	}

	return -1;
}
