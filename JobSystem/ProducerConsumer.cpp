#include "stdafx.h"
#include "ProducerConsumer.h"


void ProducerConsumer::Producer(int n)
{
	for (int i = 0; i < n; ++i)
	{
		lock_guard<mutex> lock(mtx);
	}
}

void ProducerConsumer::Consumer()
{
}

