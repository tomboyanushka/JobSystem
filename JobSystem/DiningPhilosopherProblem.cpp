#include "DiningPhilosopherProblem.h"



void philosopher::dine()
{
	while (!dinnerTable.ready)
	{
		do
		{
			think();
			eat();
		} while (dinnerTable.ready);
		
	}
}

void philosopher::think()
{
}

void philosopher::eat()
{
}
