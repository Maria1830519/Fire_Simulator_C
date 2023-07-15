#ifndef CLASS_H
#define CLASS_H

#include <iostream>

using namespace std;

//Cell class
class Cell
{
private:

	char state; //The state of the cell
	int burning; //Whether the cell has to change (1) the state or not (0)


public:

	Cell(char state, int burning); //Constructor

	char GetState(); //Gets Cell state
	void SetState(char state); //Changes Cell state

	int GetBurning(); //Gets burning attribute
	void SetBurning(int burning); //Changes burning attribute
};



//Forest Class
class Forest
{
private:
	Cell* map[21][21]; //Array of cells

public:
	Forest(void); //Constructor

	void print();//Method to print the forest

	void beginFire(); //Starts fire on a cell
	void ForestBurning();//Manages burning processes
	bool TreesAlive(); //Checks whether there are burning cells or not
};



//Weather Class
class Weather
{
private:
	string weatherType;
	float burnProb;
public:
	Weather(void);
	string WeatherType();
	float WeatherEffect();

};

#endif
