#include "DiningPhilosopherProblem.h"
struct fork
{
	mutex forkMtx;
};

struct table
{
	bool read = false;
	array<fork, numPhilosophers> forks;
};

struct philosopher
{

};


