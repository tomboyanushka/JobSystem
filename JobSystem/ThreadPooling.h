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
#include "ConcurrentQueue.h"

using namespace std;

class ThreadPool
{
public:
	explicit ThreadPool(size_t numberOfThreads);			
	~ThreadPool();

	using Task = function<void()>;			

	auto Enqueue(IJob* task)-> future<void>
	{
		auto wrapper = make_shared<packaged_task<void()>>([task] { task->Execute(); });
	
			{
				unique_lock<mutex> lock{ mtx };
				taskQueue.emplace([=] 
				{
					(*wrapper)();
				});
			}
			cv.notify_one();

			if (task->Type == JobType::PERFRAMEJOB)
			{
				perFrameJobs.emplace_back(task);
			}
			return wrapper->get_future();
	} 
	void ExecuteCallbacks();

private:
	vector<thread> threads;
	vector<IJob*> perFrameJobs;
	condition_variable cv;
	mutex mtx;
	bool isStopped = false;
	queue<Task> taskQueue;
	ConcurrentQueue<IJob> CallbackQueue;

	void Start(size_t numberOfThreads);

	void Stop() noexcept;

};