/***Driver file ***/
/*
File: main.cpp


*/


#include <iostream>
#include <utility>
#include <ctime>
#include "antH.h"
#include "doodlebugH.h"
#include "organismH.h"
using namespace std;

static int sizeOfGrid = 20;

pair< int, int> generateRandomCoordinates();
bool checkDuplicateCoordinates(vector< Organism*> bugs, pair< int, int> coordinates); //helper function; if same coordinate exists return true
pair< int, int> generateUniqCoordinates(vector< Organism*> bugs); //return uniq coordinates (use generateRandomC() & checkDuplicateC())
void generatePopulation(int numberOfBugs, int numberOfAnts, vector < Organism*> &bugs); //fill vector of certain quantity of ants and doodlebugs (ue generateUnigCoordinates)
void removeDeathBugs(vector< Organism*> &bugs); //remove organism if variable isAlive == false;
void printGrid(vector< Organism*> bugs); // visualize grid


int main()
{
	srand(time(0));
	vector< Organism*> myLittleBugs;
	myLittleBugs.reserve(105);

	generatePopulation(5, 100, myLittleBugs);

	//First print
	int step = 1;
	cout << "Step: " << step << endl;
	printGrid(myLittleBugs);
	step++;

	//move
	vector< Organism*>::iterator iter;

	cout << "Press enter to continue..." << endl;

	while(cin.get() == '\n')
	{
		//move doodlebugs
		for(iter = myLittleBugs.begin(); iter != myLittleBugs.end(); iter++)
		{
			if(dynamic_cast< Doodlebug*>(*iter) != NULL)
			{
				(*(*iter)).move(myLittleBugs);
			}
		}
		//move ants
		for(iter = myLittleBugs.begin(); iter != myLittleBugs.end(); iter++)
		{
			if(dynamic_cast< Ant*>(*iter) != NULL)
			{
				(*(*iter)).move(myLittleBugs);
			}
		}
		//breed
		int size = myLittleBugs.size();
		for(int i = 0; i < size ; i++)
		{			
			Organism* parent =  myLittleBugs.at(i);

			if((*parent).age % (*parent).breedingAge == 0)
			{
				Organism* newborn = (*(myLittleBugs.at(i))).breed(myLittleBugs);
				if( newborn != NULL)
				{
					//cout << newborn << " " << (*newborn).coordinates.first << ", " << (*newborn).coordinates.first << endl;
					myLittleBugs.push_back(newborn);
				}
			}
		}

		removeDeathBugs(myLittleBugs);
		//print
		cout << endl << endl;
		cout << "Step: " << step << endl << endl;
		printGrid(myLittleBugs);
		step++;	
		cout << "Press enter to continue..." << endl;
	}

	return 0;
}

pair< int, int> generateRandomCoordinates()
{	
	int x = rand() % (sizeOfGrid);
	int y = rand() % (sizeOfGrid);
	pair< int, int> coordinates(x, y);
	return coordinates;
}

bool checkDuplicateCoordinates(vector< Organism*> bugs, pair< int, int> coordinates)
{
	//if same coordinate exists return true
	vector< Organism*>::iterator iter;

	for(iter = bugs.begin(); iter != bugs.end(); iter++)
	{
		if((*iter) != NULL)
		{
			if((*(*iter)).coordinates == coordinates) return true;
		}
	}


	return false;
}

pair< int, int> generateUniqCoordinates(vector< Organism*> bugs)
{
	pair< int, int> tempC = generateRandomCoordinates();
	while(checkDuplicateCoordinates(bugs, tempC))
	{
		tempC = generateRandomCoordinates();
	}
	return tempC;
}

void generatePopulation(int numberOfBugs, int numberOfAnts, vector < Organism*> &bugs)
{
	for(int i = 0; i < numberOfBugs; i++)
	{
		bugs.push_back(new Doodlebug(generateUniqCoordinates(bugs)));
	}
	for(int i = 0; i < numberOfAnts; i++)
	{
		bugs.push_back(new Ant(generateUniqCoordinates(bugs)));
	}
}

void removeDeathBugs(vector< Organism*> &bugs) // remove death bugs and ants X_X
{
	vector< Organism*>::iterator iter;

	for(int i = 0; i < bugs.size(); )
	{
		if(!(*(bugs.at(i))).isAlive)
		{
			bugs.erase(bugs.begin() + i);
		}
		else
		{
			i++;
		}
	}
}

void printGrid(vector< Organism*> bugs)
{
	char grid[20][20]; //create 2D-array change to vector
	for(int i = 0; i < 20; i++) //fill 2D-array
	{
		for(int j = 0; j < 20; j++)
		{
			grid[i][j] = ' ';
		}
	}


	vector< Organism*>::iterator iter;
	for(iter = bugs.begin(); iter != bugs.end(); iter++) //settle bugs into 2D-array
	{
		if((*(*iter)).isAlive)
		{
			Organism* tempOrg = *iter;
			//cout << (*tempOrg).coordinates.first << "|" << (*tempOrg).coordinates.second << endl;
			grid[(*tempOrg).coordinates.first][(*tempOrg).coordinates.second] = (*tempOrg).image;
		}
	}

	//print array
	cout << "|  |" ;
	for(int i = 0; i < 20; i++)
	{
		if( i < 10)
			cout << i << " |";
		else
			cout << i << "|";
	}
	cout << endl;
	for(int i = 0; i < 21; i++)
	{
		cout << "---";
	}
	cout << "-";
	cout << endl;
	for(int i = 0; i < 20; i++)
	{
		if(i < 10)
		{cout << "|" << i << " |";}
		else
		{cout << "|" << i << "|";}
		for(int j = 0; j < 20; j++)
		{
			cout << grid[i][j] << " |";
		}
		cout << endl;
		for(int i = 0; i < 21; i++)
		{
			cout << "---";
		}
		cout << "-";
		cout << endl;
	}
}