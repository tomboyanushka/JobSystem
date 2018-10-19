#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
mutex mtx;
condition_variable cv;

class ProducerConsumer
{

private:

	void Producer(int n);
	void Consumer();
public:


	ProducerConsumer() {};
	~ProducerConsumer() {};
};

