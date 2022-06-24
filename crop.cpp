/*
Name: Marlon Alejandro, 5002573038, 1001, ASSIGNMENT_3
Description: Defines constructors, functions, initialized varibles
of our Garden cass and Crop classes and integrate them together to similiate
growth of a garden
Input: User inputed
Output: Output garden progress to terminal and logs errors
*/
#include "crop.h"
#include "garden.h"
/* ------------------ Static intializers ------------------*/
int Crop::totalCrops = 0;
int Corn::cornsHarvested = 0;
int Watermelon::watermelonsHarvested = 0;
int Sunflower::sunflowersHarvested = 0;
/* ------------------ Base class Crop class ------------------*/
/* Initializes the growthPerDay member, sets the crop to 0% grown, and increments the total crop count*/
Crop::Crop(int growth_per_day, int x, int y)
{ 
	this->growthPerDay = growth_per_day;
	this->x = x;
	this->y = y;
	growthPercent = 0; 
	totalCrops++;
}
/* Grows this crop by the percent it grows every day */
void Crop::grow()
{
	growthPercent += growthPerDay;
	if (growthPercent >= 100) //If the crop is fully grown, harvest it
	{
		this->onHarvest();
		Garden::getMainGarden()->removeCrop(x, y);
	}
}
/* ------------------ Corn functions ------------------*/
/*This is called whenever a Corn reaches matrurity and is harvested*/
void Corn::onHarvest()
{
	//Increment the total number of corns harvested
	cornsHarvested++;
	//Plant a corn in the square to the right of this one if it is open
	Garden* garden = Garden::getMainGarden();
	garden->plantCrop(x + 1, y, CROP_TYPE::CORN);
}
/* Gets the character to display the corn with given its current growth progress */
char Corn::getDisplayChar()
{
	if (growthPercent < 20)
		return '.';
	else if (growthPercent < 80)
		return 'c';
	else
		return 'C';
}
/* Corn constructor just calls the base class Crop contructor with relevant args */
Corn::Corn(int x, int y) : Crop(10, x, y)
{
	//Do nothing in the body
	//The call to the Crop constructor will set the growthPerDay to 10 and the x and y to the passed values
}
/* ------------------ Watermelon functions ------------------*/
/**/
void Watermelon::onHarvest()
{
	//TODO: YOUR CODE HERE
	//Increment the total number of watermelons harvested
	watermelonsHarvested++;
	//Try to plant new watermelons above and below this one (use plantCrop)
	Garden* garden = Garden::getMainGarden();
	garden->plantCrop(x, y+1, CROP_TYPE::WATERMELON);
	garden->plantCrop(x, y-1, CROP_TYPE::WATERMELON);
}
/*  Gets the character to display the corn with given its current growth progress */
char Watermelon::getDisplayChar()
{
	if (growthPercent < 32)
		return '_';
	else if (growthPercent < 88)
		return 'w';
	else
		return 'W';
}
/**/
Watermelon::Watermelon(int x, int y): Crop(8,x,y) //TODO: YOUR CODE HERE
{
	//Do nothing in the body, call the base class Crop constructor similar to the Corn class,
	//but with a growth rate of 8
}
/* ------------------ Sunflower functions ------------------*/
/**/
void Sunflower::onHarvest()
{
	//TODO: YOUR CODE HERE
	//Increment the count of sunflowers harvested
	sunflowersHarvested++;
	//Then, try to plant sunflowers in the spaces above, below, right, and left of the current space
	Garden* garden = Garden::getMainGarden();
	garden->plantCrop(x, y+1, CROP_TYPE::SUNFLOWER);
	garden->plantCrop(x, y-1, CROP_TYPE::SUNFLOWER);
	garden->plantCrop(x-1, y, CROP_TYPE::SUNFLOWER);
	garden->plantCrop(x+1, y, CROP_TYPE::SUNFLOWER);

}
/*  Gets the character to display the corn with given its current growth progress */
char Sunflower::getDisplayChar()
{
	if (growthPercent < 40)
		return '\'';
	else if (growthPercent < 80)
		return '|';
	else
		return 'O';
}
/**/
Sunflower::Sunflower(int x, int y): Crop(20,x,y)//TODO: YOUR CODE HERE
{
	//Do nothing in the body, call the base class Crop constructor similar to the Corn class,
	//but with a growth rate of 20
}