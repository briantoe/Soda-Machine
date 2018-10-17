

#ifndef  DRINKMACHINE_H
#define DRINKMACHINE_H


struct drinkItem
{
	char drinkName[256]; // 256 bytes
	double price;		//
	int inventory;
	int drinksPurchased; // = 0;
	int id;
};

struct drinkMachine
{
	int currentLocation;
	int version; //= 1; 
	int numOfDrinkItems; // 4 bytes
	struct drinkItem * drinks;
};



#endif // ! DRINKMACHINE_H
