#pragma once
#include <functional>
#include <vector>
#include <iostream>
#include <future>
#include <thread> 
#include <condition_variable>
#include <mutex>
#include <queue>
#include "IJob.h"

using namespace std;

class ThreadPool
{
public:
	explicit ThreadPool(size_t numberOfThreads);			//explicit: You can only assign values that match the values of the class type.
	~ThreadPool();

	using Task = function<void()>;			

	//template<class T>
	auto Enqueue(IJob* task)-> future<void>
	{
		//auto wrapper = make_shared<packaged_task<decltype(task()) ()>>(move(task));
		auto wrapper = make_shared<packaged_task<void()>>([task] { task->Execute(); });
	
			{
				unique_lock<mutex> lock{ mtx };
				taskQueue.emplace([=] 
				{
					(*wrapper)();
				});
			}
			cv.notify_one();
			return wrapper->get_future();
	} 
private:
	vector<thread> threads;
	condition_variable cv;
	mutex mtx;
	bool isStopped = false;
	queue<Task> taskQueue;

	void Start(size_t numberOfThreads);

	void Stop() noexcept;

};