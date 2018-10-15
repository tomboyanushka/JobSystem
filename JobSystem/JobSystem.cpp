// JobSystem.cpp : Defines the entry point for the console application.
//
//A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope.
//We can capture external variables from enclosing scope by three ways :
//Capture by reference
//Capture by value
//Capture by both(mixed capture)
//
//Syntax used for capturing variables :
//[&] : capture all external variable by reference
//[=] : capture all external variable by value
//[a, &b] : capture a by value and b by reference

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <stdio.h>

HANDLE hSemaphore;

using namespace std;

static const int num_threads = 10;


void callThread()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << "Hello from the other thread! \n" << i << endl;
	}	

}

int main()
{
	//lambda function
	auto func = []() //[] is called capture specification
	{
		cout << "Hello from the lambda side \n";
	};

	thread t[num_threads];
	//launching threads
	for (int i = 0; i < num_threads; ++i)
	{
		t[i] = thread(func);
	}

	

	cout << "launched from main \n";
	

	//join the threads to main
	for (int i = 0; i < num_threads; ++i)
	{
		t[i].join();
	}



	getchar();
	return 0;
}

