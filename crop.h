#ifndef CROP_H
#define CROP_H

//Abstract base class for all Crops. This cannot be instantiated, but acts as a common parent for all the type
//of crops we'll have
class Crop
{
	static int totalCrops;
	protected: 
		int x, y;
		int growthPercent, growthPerDay;
	public:
		virtual void onHarvest() = 0; //Abstract function called when a crop is done growing
		void grow();
		virtual char getDisplayChar() = 0;

		static int getTotalCrops() { return totalCrops; }

		Crop(int growth_per_day, int x, int y);
		virtual ~Crop() {} //Virtual destructor to allow derived classes to be deleted correctly
};

class Corn : public Crop
{
	public:
		static int cornsHarvested;

		//We must implement these abstract base class functions here to make this class non-abstract
		void onHarvest();
		char getDisplayChar();

		Corn(int x, int y);
};

class Watermelon : public Crop
{
	public:
		static int watermelonsHarvested;

		void onHarvest();
		char getDisplayChar();

		Watermelon(int x, int y);
};

class Sunflower : public Crop
{
	public:
		static int sunflowersHarvested;

		void onHarvest();
		char getDisplayChar();

		Sunflower(int x, int y);
};
#endif
