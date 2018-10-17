#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "drinkmachine.h"
//#include "drinkmachine.c"
enum Purchase { PURCHASED, INVALID, NOT_AVAILABLE, INSUFFICIENT_FUNDS };


int main()
{
	int userInput = -100;
	char prompt1[256] = "Enter a drink id for the drink you want to purchase or 0 to quit.\n";
	char thankYou[256] = "Thank you for using the drink machine.\n";

	/*
	while (userInput != 0)
	{


	}
	*/


	system("pause");
	return 0;
}
/*
int main()
{
	struct drinkMachine *test = create();
	char *name = test->drinks[1].drinkName;
	printf("%s\n", name);

	struct drinkItem *first = firstDrink(test);

	char *nameofFirst = first->drinkName;

	printf("%s\n", nameofFirst);

	struct drinkItem *next = nextDrink(test);
	next = nextDrink(test); // uwu
	next = nextDrink(test);
	next = nextDrink(test);
	next = nextDrink(test); // uwu
	next = nextDrink(test);
	next = nextDrink(test);
	next = nextDrink(test);

	char *nameOfNext;
	if (test->currentLocation != -1) // if we haven't exceed the range of drinks in the machine.
	{
		nameOfNext = next->drinkName;
	}
	else // we left the range of drinks
	{
		nameOfNext = "big gay";
	}
	printf("%s\n", nameOfNext);

	dumpDrinkMachine(test);

	system("pause");
	return 0;
}
*/

