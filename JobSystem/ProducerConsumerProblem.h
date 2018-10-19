#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include <chrono>

using namespace std;


class ProducerConsumerProblem
{
	mutex mtx;
	condition_variable cv;
	queue<int> q;
public:
	ProducerConsumerProblem() {};
	~ProducerConsumerProblem() {};

	void Producer();
	void Consumer();
	void ExecuteProblem();


	bool finished = false;
};

