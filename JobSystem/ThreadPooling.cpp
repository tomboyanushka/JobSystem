#include "ThreadPooling.h"

ThreadPool::ThreadPool(size_t numberOfThreads)
{
	Start(numberOfThreads);
}

ThreadPool::~ThreadPool()
{
	Stop();
}

void ThreadPool::Enqueue(Task task)
{
	{
		unique_lock<mutex> lock{ mtx };
		taskQueue.emplace(move(task));
	}
	cv.notify_one();
}

void ThreadPool::Start(size_t numberOfThreads)
{
	for (auto i = 0; i < numberOfThreads; ++i)
	{
													//emplace_back: Inserts a new element at the end of the vector, right after its current last element. 
													//This new element is constructed in place using args as the arguments for its constructor
		threads.emplace_back([=]					//why = ?
		{
			while (true)
			{
				Task firstTask;
				{
					unique_lock<mutex> lock{ mtx };
					cv.wait(lock, [=] { return isStopped || !taskQueue.empty(); });

					if (isStopped && taskQueue.empty())
					{
						break;
					}

					firstTask = move(taskQueue.front());
					taskQueue.pop();
				}


				firstTask();
			}
		});
	}
}

void ThreadPool::Stop() noexcept
{
	{
		unique_lock<mutex> lock{ mtx };
		isStopped = true;
	}

	cv.notify_all();

	for (auto &thread : threads)
	{
		thread.join();
	}

		
}
