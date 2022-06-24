#include "crop.h"
#include "garden.h"
#include <iostream>
#include <time.h> 
#include <cstdlib>
#include <string>

using namespace std;

//Function prototypes
void fillGarden(Garden* garden, int width, int height);
int readInt();

int main(int argc, char** argv)
{
	unsigned int seed = 400805; //Variable to hold the seed for RNG
	if (argc == 2) //If we have a commandline arg, try to use it as the seed
	{
		try { seed = stoi(argv[1]); }
		catch(...) { cout << "Seed is invalid. Did you provide a number?" << endl; }
	}
	srand(seed); //Seed the RNG

	//Create the Garden and fill it
	int width, height, days;
	cout << "Please enter the width of the Garden plot" << endl;
	width = readInt();
	cout << "Please enter the height of the Garden plot" << endl;
	height = readInt();
	cout << "How many days should the Garden go for?" << endl;
	days = readInt();
	Garden* garden = new Garden(height, width);

	//After creating the Garden, fill it
	fillGarden(garden, width, height);

	//Now that the Garden is allocated, let's start the main loop
	for (int day = 0; day < days; day++)
	{
		cout << "-------------- Garden Day " << day << "--------------" << endl;
		garden->printGarden();
		garden->passDay();
	}

	//Print the results
	cout << "--------------Final Garden--------------" << endl;
	garden->printGarden();
	cout << "Total number of crops planted: " << Crop::getTotalCrops() << endl;
	cout << "Corn harvested: " << Corn::cornsHarvested << endl;
	cout << "Watermelons harvested: " << Watermelon::watermelonsHarvested << endl;
	cout << "Sunflowers harvested: " << Sunflower::sunflowersHarvested << endl;
	cout << "Crops unharvested: " <<
		Crop::getTotalCrops() - Corn::cornsHarvested - Watermelon::watermelonsHarvested - Sunflower::sunflowersHarvested
		<< endl;

	delete garden; //Finally, delete the Garden before the program ends

	return 0;
}

//Fills the garden with a random amount of crops
const int chance = 5; //1 in chance ability to put a crop at any position
void fillGarden(Garden* garden, int width, int height)
{
	cout << "Populating Garden..." << endl;
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			//Figure out whether or not to add a crop
			if (rand() % chance == 0)
			{
				//garden->plantCrop(j, i, static_cast<CROP_TYPE>(rand() % 3));
				//If we will put a crop, randomly select one
				switch (rand() % 3)
				{
					case 0:
						garden->plantCrop(j, i, CROP_TYPE::CORN);
						break;
					case 1:
						garden->plantCrop(j, i, CROP_TYPE::WATERMELON);
						break;
					case 2:
						garden->plantCrop(j, i, CROP_TYPE::SUNFLOWER);
						break;
				}
				 
			}
		}
	}
}

/*Reads an int from cin and returns it, while doing error checking*/
int readInt()
{
	int returnVal;
	cin >> returnVal;
	while (cin.fail() || returnVal < 0)
	{
		cout << "Error, invalid value. Please enter a positive integer" << endl;
		cin.clear();
		cin.ignore(512, '\n');
		cin >> returnVal;
	}

	return returnVal;
}