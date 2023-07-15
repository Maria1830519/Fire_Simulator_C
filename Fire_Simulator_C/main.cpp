#include "Class.h"
#include <iostream>
#include <stdlib.h>



using namespace std;


//Cell
//Constructor
Cell::Cell(char state, int burning)
{
	this->state = state;
	this->burning = burning;
}

//Gets Cell state
char Cell::GetState()
{
	return state;
}

//Changes Cell state
void Cell::SetState(char state)
{
	this->state = state;
}

//Gets burning attribute
int Cell::GetBurning()
{
	return burning;
}

//Changes burning attribute
void Cell::SetBurning(int burning)
{
	this->burning = burning;
}

//Forest 
//Constructor
Forest::Forest(void)
{
	//for loop to set the Cell objects on the array
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			//Top and bottom borders
			if ((i == 0) || (i == 20))
			{
				map[i][j] = new Cell('0', 0);
			}
			//Right and left borders
			else if ((j == 0) || (j == 20))
			{
				map[i][j] = new Cell('0', 0);
			}
			//Trees
			else
			{
				map[i][j] = new Cell('*', 0);
			}

		}
	}

}

//Method that prints forest map
void Forest::print()
{
	Weather weather;

	//Legend informing the user the meaning of the symbols on the map
	cout << "Legend: " << endl << "Empty or Burnt : 0  -  Tree: *  -  Burning: #" << endl;
	cout << "Weather: " << weather.WeatherType() << endl;
	cout << endl;


	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			cout << map[i][j]->GetState() << ' ';
		}

		cout << endl;
	}
}

//Method that starts fire
void Forest::beginFire()
{
	srand((unsigned)time(NULL));

	int randi = 1 + (rand() % 19); //Sets random i
	int randj = 1 + (rand() % 19); //Sets random j

	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			//Sets the cell on the middle of the map on fire
			if (i == randi && j == randj)
			{
				map[i][j]->SetState('#');
			}


		}

	}
}

//Manages the process of burning 
void Forest::ForestBurning()
{
	Weather weather;
	srand((unsigned)time(NULL));

	float respawnProb;
	float prob;

	//Checks if neighboor trees on fire and change burning state
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j < 19; j++)
		{
			if (((map[i - 1][j]->GetState() == '#') || (map[i + 1][j]->GetState() == '#') || (map[i][j - 1]->GetState() == '#') || (map[i][j + 1]->GetState() == '#')) && (map[i][j]->GetState() == '*'))
			{
				map[i][j]->SetBurning(1);
			}


		}

	}

	//RESPAWN
	//Turns burning trees into empty spaces (brunt)

	//Starts a random number
	//If number is higher than 0.6, trees respawns
	//If number is lower, it doesn't
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			respawnProb = (float)rand() / RAND_MAX;

			if ((map[i][j]->GetState() == '0') && (respawnProb <= 0.15))
			{
				map[i][j]->SetState('*');
			}
		}
	}



	//Turns burning trees into empty spaces (burnt)
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			if (map[i][j]->GetState() == '#')
			{
				map[i][j]->SetState('0');
			}


		}

	}

	//Starts random number
	//If number is lower than WeatherEffect, then the tree with burning attribute = 1 burns
	//if number is higher, tree stays as tree
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			prob = (float)rand() / RAND_MAX;
			if ((map[i][j]->GetBurning() == 1) && (prob <= weather.WeatherEffect()))
			{
				map[i][j]->SetState('#');
				map[i][j]->SetBurning(0);
			}
			else
			{
				map[i][j]->SetBurning(0);
			}


		}

	}
}

//Checks whether there are burning trees or not
bool Forest::TreesAlive()
{
	bool burning = false;

	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			if (map[i][j]->GetState() == '#')
			{
				burning = true;
			}

		}

	}

	return burning;
}

Weather::Weather() //Constructor
{
	weatherType = "";
}

string Weather::WeatherType() //Sets random Weather
{
	srand((unsigned)time(NULL));


	int random = 1 + (rand() % 30);
	if (random <= 10)
	{
		weatherType = "Dry";
	}
	else if ((10 < random) && (random <= 20))
	{
		weatherType = "Normal";
	}
	else
	{
		weatherType = "Raining";
	}
	return weatherType;
}

float Weather::WeatherEffect() //Sets burning probability depending on Weather
{
	if (WeatherType() == "Dry")
	{
		burnProb = 0.8f;
	}
	else if (WeatherType() == "Raining")
	{
		burnProb = 0.35f;
	}
	else if (WeatherType() == "Normal")
	{
		burnProb = 0.5f;
	}
	return burnProb;
}

//Main program
int main()
{
	Weather weather;
	Forest forest;

	cout << "Welcome to the Fire Simulator!!" << endl;
	cout << endl;

	forest.beginFire();
	forest.print();
	cout << "Press any key to continue" << endl;

	system("pause");


	while (forest.TreesAlive() == true)
	{
		system("cls");
		forest.ForestBurning();
		forest.print();
		system("pause");
	}

	system("cls");

	cout << "Simulation Finished" << endl;

	forest.print();
	system("pause");

	return 0;
}