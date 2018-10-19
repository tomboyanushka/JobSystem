//#pragma once
//// JobSystem.cpp : Defines the entry point for the console application.
/////lambda expression
////A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope.
////We can capture external variables from enclosing scope by three ways :
////Capture by reference
////Capture by value
////Capture by both(mixed capture) 
////
////Syntax used for capturing variables :
////[&] : capture all external variable by reference
////[=] : capture all external variable by value
////[a, &b] : capture a by value and b by reference
//
//
/////condition_variable
////A condition variable is an object able to block the calling thread until notified to resume.
////It uses a unique_lock(over a mutex) to lock the thread when one of its wait functions is called.The thread remains blocked until woken up by another thread that calls a notification function on the same condition_variable object.
////Objects of type condition_variable always use unique_lock<mutex> to wait
//
//#include "stdafx.h"
//#include <iostream>
//#include <cstdlib>
//#include <thread>
//#include <stdio.h>
//#include <mutex>
//#include <condition_variable>
//#include "ProducerConsumer.cpp"
//
//static const int num_threads = 10;
//mutex mtx;
//condition_variable cv;
//bool ready = false;
//
//void printID(int id)
//{
//	unique_lock<mutex> lock(mtx);
//	while (!ready)
//	{
//		cv.wait(lock);
//	}
//	cout << "thread " << id << "\n";
//}
//
//void go()
//{
//	unique_lock<mutex> lock(mtx);
//	ready = true;
//	cv.notify_all();
//}
//
//void callThread()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "Hello from the other thread! \n" << i << endl;
//	}	
//
//}
//
//int execute()
//{
//	//lambda function
//	auto func = []() //[] is called capture specification
//	{
//		cout << "Hello from the lambda side \n";
//	};
//
//	thread t[num_threads];
//	//launching threads
//	for (int i = 0; i < num_threads; ++i)
//	{
//		t[i] = thread(func);
//	}
//
//	
//
//	cout << "launched from main \n";
//	
//
//	//join the threads to main
//	for (int i = 0; i < num_threads; ++i)
//	{
//		t[i].join();
//	}
//
//	//spawn threads
//	thread threads[10];
//	for (int i = 0; i < 10; ++i)
//	{
//		threads[i] = thread(printID, i);
//
//	}
//	cout << "10 threads racing \n";
//	cin.get();
//	go();
//
//	for (auto& th : threads)
//	{
//		th.join();
//	}
//}