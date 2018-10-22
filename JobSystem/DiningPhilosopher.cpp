#include "DiningPhilosopher.h"
auto eat = [](Chopstick* leftChopstick, Chopstick* rightChopstick, int philosopherNumber)
{
	while (true)
	{
		if (leftChopstick == rightChopstick)
			throw exception("Left and right chopsticks are the same");

		lock(leftChopstick->mtx, rightChopstick->mtx);
		lock_guard<mutex> left(leftChopstick->mtx, adopt_lock);
		lock_guard<mutex> right(rightChopstick->mtx, adopt_lock);

		string philosopher = "Philosopher " + to_string(philosopherNumber) + " eats. \n";
		string chopstick = "Philosopher " + to_string(philosopherNumber) + " picked Chopstick number " 
			+ to_string(leftChopstick->chopstickNumber) + " and " + to_string(rightChopstick->chopstickNumber);
		cout << philosopher;
		cout << chopstick;

	}

};

void DiningPhilosopher::Init()
{
	//creating chopsticks equal to number of philosophers
	vector<unique_ptr<Chopstick>> chopsticks(numPhilosophers);
	for (int i = 0; i < numPhilosophers; ++i)
	{
		auto c1 = unique_ptr<Chopstick>(new Chopstick());
		c1->chopstickNumber = i;
		chopsticks[i] = move(c1);
	}
	// This is where we create philosophers, each of 5 tasks represents one philosopher. 
	vector<thread> tasks(numPhilosophers);

	tasks[0] = thread(eat,
		chopsticks[0].get(),						//left chopstick #1
		chopsticks[numPhilosophers - 1].get(),		//right chopstick #5
		0 + 1									//philosopher number
);

	for (int i = 1; i < numPhilosophers; ++i)
	{
		tasks[i] = thread(eat,
			chopsticks[i - 1].get(),				//left chopstick 
			chopsticks[i].get(),					//right chopstick 
			i + 1									//philosopher number
	);
	}

	//std::mem_fn is a call wrapper.

	for_each (tasks.begin(), tasks.end(), mem_fn(&thread::join));

}


