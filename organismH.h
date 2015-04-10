/***Header Organism class***/
/*File: organismH.h

Constructors:

	Organism(); default constructor; assign: coordinates and age = 0, isAlife = true, sizeOfGrid = 20 
	Organism(pair< int, int> p_pair); assign coordinates

Functions:

	Organism* breed(vector< Organism*> bugs);
		allows breed only if for this organism (age % breedingAge) = 0
		returns new organism Ant or Doodlebug depending on the parent class (uses dynamic_cast for checking)
		calls helper function generateCoordinates(int direction);
		parameter "vector< Organism*>" is for helper function WatchingCoordinate

	virtual void move(vector< Organism*> bugs);
		changes coordinates of current organism (ant or doodlebug);
		calls helper function generateCoordinates(int direction);
		parameter "vector< Organism*>" using for helper function WatchingCoordinate

Helper functions:

	pair< int, int> generateCoordinates(int direction);
		return pair of new coordinates near organism depending on the direction(0, 1, 2, or 3)

	virtual int watchingCoordinate(vector< Organism*> bugs, pair< int, int> tempC);
		check is organism with same pair coordinates is already exists in array, if yes: return - 1

Variables:

	pair< int, int> coordinates;
		keeps coordinates, coordinates.first is x, coordinates.second is y

	bool isAlive; 
		if ant was eaten or doodlebug die from starvation,  isAlive changed to 'false' (using inside doodlebug class)

	char image;
		assigned character in child classes, used for printout organism

	int age;
		accumulates age of organism

	int breedingAge;
		assigned in child classes how often organism can breed

*/


#ifndef ORGANISM_MARIIALAB
#define ORGANISM_MARIIALAB

#include <vector>
#include <utility>
using namespace std;

class Organism
{
public:
	//Constructors
	Organism();
	Organism(pair< int, int> p_pair);

	Organism* breed(vector< Organism*> bugs);
	virtual void move(vector< Organism*> bugs);

	//variables
	pair< int, int> coordinates;
	bool isAlive;
	char image;
	int age;
	int breedingAge;

protected:
	//Hepler functions
	//find is in certain coordinate is already another bug, if so return index
	virtual int watchingCoordinate(vector< Organism*> bugs, pair< int, int> tempC);
	pair< int, int> generateCoordinates(int direction);	

	//keep current size of grid
	int sizeOfGrid;
};

#endif;