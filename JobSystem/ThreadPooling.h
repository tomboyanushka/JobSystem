#pragma once
#include <functional>
#include <vector>
#include <thread> 
#include <condition_variable>
#include <mutex>
#include <queue>

using namespace std;

class ThreadPool
{
public:
	explicit ThreadPool(size_t numberOfThreads);			//explicit: You can only assign values that match the values of the class type.
	~ThreadPool();

	using Task = function<void()>;			//I do not understand this

	void Enqueue(Task task);
private:
	vector<thread> threads;
	condition_variable cv;
	mutex mtx;
	bool isStopped = false;
	queue<Task> taskQueue;

	void Start(size_t numberOfThreads);

	void Stop() noexcept;

};