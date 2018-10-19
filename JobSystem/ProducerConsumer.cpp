#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;
mutex mtx;
condition_variable cv;
queue<int> q;

bool finished = false;


void Producer(int n)
{
	for (int i = 0; i < n; ++i)
	{
		{
			lock_guard<mutex> lock(mtx);
			q.push(i);
			cout << "Pushing " << i << endl;
		}
		cv.notify_all();
	}
	{
		lock_guard<mutex> lock(mtx);
		finished = true;
	
	}
	cv.notify_all();
}

void Consumer()
{
	while (true)
	{
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [] {return finished || !q.empty(); });
		while (!q.empty())
		{
			cout << "Consuming " << q.front() << endl;
			q.pop();
		}
		if (finished)
		{
			break;
		}
	}
}

int main()
{
	thread t1(Producer, 10);
	thread t2(Consumer);
	t1.join();
	t2.join();

	cout << "Completed! " << endl;
	getchar();
	return 0;
}

