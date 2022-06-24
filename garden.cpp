/*
Name: Marlon Alejandro, 5002573038, 1001, ASSIGNMENT_3
Description: Defines constructors, functions, initialized varibles
of our Garden cass and Crop classes and integrate them together to similiate
growth of a garden
Input: User inputed
Output: Output garden progress to terminal and logs errors
*/
#include "garden.h"
#include <iostream>
#include <iomanip>
using namespace std;
Garden* Garden::mainGarden = nullptr; //Initialize the static reference
/**/
Garden::Garden(int height, int width)
{
	logFile.open("garden_log.txt"); //We'll log error messages to a log file
	//Set the height and width members based on the rows and columns, respectively
	//Allocate a dynamic 2D array of Crop*s and fill it with nullptr by default
	//We will have the gardenArr point to this array, you won't want any locals
	//We want to make an empty 2D grid to represent the Garden in the constructor
	
	//Start by allocating the single column of Crop**s, then 
	//Allocate a row of Crop*s for each spot in the column
	//Generally, 2D arrays are done height first, then width (row major)
	//(Refer to the dynamic 2D array example on Canvas for reference)
	//Finally, go through the 2D array you made and set all of the entries to nullptr
	//There is nothing special about it being dynamic, try to traverse the allocated array just like you would
	//any other 2D array. Alternatively, you can do this in the same place as the allocation
	//TODO: YOUR CODE HERE
	this->height= height;
	this->width=width;
	
	gardenArr= new Crop**[height];
	for(int i=0; i<height; i++){
		gardenArr[i] = new Crop*[width];
	}
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			gardenArr[i][j] =  nullptr;
		}
	}
	mainGarden = this; //Let's keep a static reference to our Garden for ease of access
}
/**/
Garden::~Garden()
{
	logFile.close(); //Close the log file now that we're done
	//Finish the destructor to deallocate all of the memory we allocated
	//This should be done in the opposite order of our allocations, so delete the contents of the 
	//array first, since it contains pointers, then each row, then the single column
	//Start by remove all crops from the garden. Check they exist first (are not nullptr)
	//Then delete the rows, gardenArr[i]
	//Then delete the single column pointed to by gardenArr
	//TODO: YOUR CODE HERE
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			delete gardenArr[i][j];
		}
	}
	for(int i=0; i<height; i++){
		delete[] gardenArr[i];
	}
	delete[] gardenArr;
}
/**/
void Garden::removeCrop(int x, int y)
{
	//This should delete the crop at the given x, y position in the gardenArr if it exists (is not null)
	//Then set that space to nullptr after deleting to make the spot empty
	//Remember that in row major form, y comes before x in our 2D array
	//TODO: YOUR CODE HERE
	if (gardenArr[y][x]!=nullptr){
		delete gardenArr[y][x];
		gardenArr[y][x]=nullptr;
	}
}
/* Plants a crop of the given CROP_TYPE at the x and y coordinate given */
void Garden::plantCrop(int x, int y, CROP_TYPE type)
{
	//Check if the crop would go out of bounds first
	if (y >= height || y < 0 || x >= width || x < 0)
	{
		logFile << "Tried to plant a crop out of bounds at (" << x << ", " << y << ") " << endl;
		// switch (type)
		// {
		// 	case CROP_TYPE::CORN:
		// 		logFile<< "CORN" << endl;
		// 		return;
		// 	case CROP_TYPE::WATERMELON:
		// 		logFile<< "WATERMELON" << endl;
		// 		return;
		// 	case CROP_TYPE::SUNFLOWER:
		// 		logFile<< "SUNFLOWER" << endl;
		// 		return;
		// }
		//debugging
		return;
	}
	if (gardenArr[y][x] != nullptr)
	{
		logFile << "Could not plant crop on top of existing crop" << endl; 
		// switch (type)
		// {
		// 	case CROP_TYPE::CORN:
		// 		logFile<< " (" << x << ", " << y << ") " << "CORN" << endl;
		// 		return;
		// 	case CROP_TYPE::WATERMELON:
		// 		logFile<< " (" << x << ", " << y << ") " "WATERMELON" << endl;
		// 		return;
		// 	case CROP_TYPE::SUNFLOWER:
		// 		logFile<< " (" << x << ", " << y << ") " "SUNFLOWER" << endl;
		// 		return;
		// }
		//debugging

		return;
	}
	//Figure out which crop to plant and plant it
	switch (type)
	{
		case CROP_TYPE::CORN:
			gardenArr[y][x] = new Corn(x, y);
			return;
		case CROP_TYPE::WATERMELON:
			gardenArr[y][x] = new Watermelon(x, y);
			return;
		case CROP_TYPE::SUNFLOWER:
			gardenArr[y][x] = new Sunflower(x, y);
			return;
	}
}
/* Passes one single day by updating all of the crops so they grow */
void Garden::passDay()
{
	int i, j;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			if(gardenArr[i][j] != nullptr) gardenArr[i][j]->grow();
}
/* Prints the Garden as a grid to cout */
void Garden::printGarden()
{
	int i, j;
	//Print the top bar
	cout << setw(2 * (width + 1)) << setfill('-') << "" << endl;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			//For each space, print an empty char or the char of the Crop at the place
			cout << "|" <<
				(gardenArr[i][j] == nullptr ? ' ' : gardenArr[i][j]->getDisplayChar()); 
		}
		cout << "|" << endl;
	}
	//Print the bottom bar
	cout << setw(2 * (width + 1)) << setfill('-') << "" << endl << endl;
}