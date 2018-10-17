#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "drinkmachine.h"


struct drinkMachine* create();
void destroy(struct drinkMachine * machine);

struct drinkItem* firstDrink(struct drinkMachine * machine);
struct drinkItem* nextDrink(struct drinkMachine * machine);

int items(struct drinkMachine* machine);
int available(struct drinkMachine* machine, int id);
double cost(struct drinkMachine* machine, int id);
enum Purchase purchase(struct drinkMachine * machine, int id, double money, double * change);
void dumpDrinkMachine(struct drinkMachine * machine);

enum Purchase { PURCHASED, INVALID, NOT_AVAILABLE, INSUFFICIENT_FUNDS };
const int INVALID_INDEX = -1;


struct drinkMachine * create()
{
	struct drinkMachine * machine;


	FILE *stream = fopen("drink_machine.txt", "r");
	if (stream == NULL)
	{
		//free(machine);
		return NULL;
	}
	else
	{
		//char fileName[256];
		int numOfDrinks;
		int t = sizeof(struct drinkItem);
		fscanf(stream, "%d", &numOfDrinks); // reading in an integer
											// params: (stream of type FILE, "%specifier", &var to assign to)
		//struct drinkItem *items = malloc(numOfDrinks * (sizeof(int) + sizeof(int) + sizeof(float) + (sizeof(char) * 256)));
		machine = malloc(sizeof(struct drinkMachine));
		machine->drinks = malloc(numOfDrinks * t);

		machine->numOfDrinkItems = numOfDrinks;
		int count = 0;
		while (numOfDrinks > 0)
		{
			char name[256];
			float price;
			int amount;
			fscanf(stream, "%s", name);
			fscanf(stream, "%f", &price);
			fscanf(stream, "%d", &amount);
			struct drinkItem temp;

			strcpy(temp.drinkName, name);
			temp.price = price;
			temp.inventory = amount;
			temp.drinksPurchased = 0;
			temp.id = count + 1;

			//items[count].drinkName = name;
			machine->drinks[count] = temp;

			numOfDrinks = numOfDrinks - 1;
			count++;
		}
		//machine->drinks = items;
		machine->version = 1;
		machine->currentLocation = INVALID_INDEX;


		return machine;
	}
}

void destroy(struct drinkMachine * machine)
{
	free(machine->drinks);
	free(machine);
}

struct drinkItem* firstDrink(struct drinkMachine * machine)
{
	if (machine->numOfDrinkItems <= 0)
	{
		machine->currentLocation = INVALID_INDEX;
		return NULL;

	}
	else
	{

		struct drinkItem * firstItem = &(machine->drinks[0]);
		machine->currentLocation = 0;
		return firstItem;
	}
	return NULL;
}

struct drinkItem* nextDrink(struct drinkMachine * machine)
{
	if (machine->currentLocation == INVALID_INDEX)
		return NULL;
	else
	{
		machine->currentLocation++;
		if (machine->currentLocation >= machine->numOfDrinkItems)
		{
			machine->currentLocation = INVALID_INDEX;
			return NULL;
		}
		int nextIndex = machine->currentLocation;
		struct drinkItem *next = &machine->drinks[nextIndex];
		return next;
	}


}



int items(struct drinkMachine* machine)
{

	return machine->numOfDrinkItems;
}


int available(struct drinkMachine* machine, int id)
{
	// should return only a 1 for true or 0 for false
	if (id > machine->numOfDrinkItems && id <= 0)
		return 0; // return false


	struct drinkItem drink;
	drink = machine->drinks[id - 1];

	if (drink.inventory == 0)
		return 0; // return false
	else
		return 1; // return true;
}

double cost(struct drinkMachine* machine, int id)
{
	if (id > machine->numOfDrinkItems && id <= 0)
		return -1; // invalid id

	struct drinkItem drink = machine->drinks[id - 1];
	return drink.price;
}

enum Purchase purchase(struct drinkMachine * machine, int id, double money, double * change)
{
	if (id > machine->numOfDrinkItems && id <= 0)
		return INVALID; // invalid id

	struct drinkItem *drink = &machine->drinks[id - 1];
	if (drink->inventory == 0)
		return NOT_AVAILABLE;

	if (drink->price > money)
		return INSUFFICIENT_FUNDS;

	drink->drinksPurchased++;
	drink->inventory--;
	*change = money - drink->price;
	return PURCHASED;
}


void dumpDrinkMachine(struct drinkMachine * machine)
{
	const int maxWidth = 5;
	printf("%*s\t", maxWidth, "Id");
	printf("%*s\t", maxWidth, "Name");
	printf("%*s\t", maxWidth, "Price");
	printf("%*s\t", maxWidth, "Qty");
	printf("%*s\t", maxWidth, "Sold");
	printf("\n");

	int numOfDrinks = machine->numOfDrinkItems;
	int count = 0;
	while (count < numOfDrinks)
	{
		printf("%*d\t", maxWidth, machine->drinks[count].id);
		printf("%*s\t", maxWidth, machine->drinks[count].drinkName);
		printf("%*F\t", maxWidth, machine->drinks[count].price);
		printf("%*d\t", maxWidth, machine->drinks[count].inventory);
		printf("%*d\t", maxWidth, machine->drinks[count].drinksPurchased);
		printf("\n");

		count++;
	}
}