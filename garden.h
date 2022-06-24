#ifndef GARDEN_H
#define GARDEN_H

#include "crop.h"
#include <fstream>

using namespace std;

enum class CROP_TYPE{ CORN, WATERMELON, SUNFLOWER };

class Garden
{
	static Garden* mainGarden; //Static reference to Garden being used
	int width, height;
	Crop*** gardenArr;
	ofstream logFile;

public:
	void printGarden();
	void plantCrop(int x, int y, CROP_TYPE type);
	void removeCrop(int x, int y); 
	void passDay();

	static Garden* getMainGarden() { return mainGarden; }

	Garden(int height, int width);
	~Garden();
};

#endif
