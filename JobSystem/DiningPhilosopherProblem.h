#pragma once

//Five silent philosophers sit at a round table with bowls of spaghetti.
//Forks are placed between each pair of adjacent philosophers.
//Each philosopher must alternately think and eat.
//However, a philosopher can only eat spaghetti when they have both left and right forks.
//Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher.
//After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others.
//A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.
//Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.
//credits/reference: https://mariusbancila.ro/blog/2017/01/16/dining-philosophers-in-cpp11/

#include <mutex>
#include <array>
#include <random>
#include <string>
#include <string_view>
using namespace std;
const int numPhilosophers = 5;

struct fork
{
	mutex forkMtx;
};

struct table
{
	bool ready = false;
	array<fork, numPhilosophers> forks;
};

struct philosopher
{
private:
	string const name;
	table const & dinnerTable;
	fork& leftFork;
	fork& rightFork;
	thread lifeThread;
	mt19937 range{ random_device{}() }; //Mersenne Twister 19937 generator; A Mersenne Twister pseudo - random generator of 32 - bit numbers with a state size of 19937 bits.

public:
	philosopher(s n, table const& t, fork& l, fork& r) :name(n), dinnerTable(t), leftFork(l), rightFork(r), lifeThread(&philosopher::dine, this)
	{
	}
	~philosopher()
	{
		lifeThread.join();
	}

	//Three main methods in the philosopher class
	//dine
	//think
	//eat
	void dine();
	void think();
	void eat();
};


class DiningPhilosopherProblem
{
	mutex mtx;
	
public:
	DiningPhilosopherProblem() {};
	~DiningPhilosopherProblem() {};

	


};




