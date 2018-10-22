#pragma once

//Five silent philosophers sit at a round table with bowls of spaghetti.
//Forks are placed between each pair of adjacent philosophers.
//Each philosopher must alternately think and eat.
//However, a philosopher can only eat spaghetti when they have both left and right forks.
//Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher.
//After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others.
//A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.
//Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.
//credits/reference: https://pm007dev.wordpress.com/tag/c11/ 

#include <mutex>
#include <array>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
static const int numPhilosophers = 5;



class DiningPhilosopher
{
public:
	
	DiningPhilosopher() {};
	~DiningPhilosopher() {};
	void Init();
	
	

};
struct Chopstick
{
public:
	Chopstick() {};
	mutex mtx;
	int chopstickNumber;

	
};

