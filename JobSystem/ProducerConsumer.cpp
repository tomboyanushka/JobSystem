//#include "stdafx.h"
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <queue>
//#include <time.h>
//#include <stdlib.h>
//#include <chrono>
//
//using namespace std;
//mutex mtx;
//condition_variable cv;
//queue<int> q;
//
//bool finished = false;
//
//
//
//void Producer()
//{
//	while(true)
//	{
//		
//		int num = rand() % 100 + 1;
//
//		unique_lock<mutex> lock(mtx); //locks everything till producer finishes producing
//		q.push(num);
//		cout << "ID " << this_thread::get_id() << "Producing " << num << endl;
//
//		cv.notify_all();
//		lock.unlock();
//		this_thread::sleep_for(chrono::milliseconds(50));
//
//	}
//	
//	
//}
//
//void Consumer()
//{
//	while (true)
//	{
//		unique_lock<mutex> lock(mtx);
//		cv.wait(lock, [] {return !q.empty(); });
//		while (!q.empty())
//		{
//			cout << "ID " << this_thread::get_id() << "Consuming "  << q.front() << endl;
//			q.pop();
//		}
//		lock.unlock();
//		this_thread::sleep_for(chrono::seconds(2));
//		
//	}
//	
//}
//
//int main()
//{	
//	srand(time(NULL));
//	
//	thread t1(Producer);
//	thread t2(Consumer);
//	//t1.join();
//	//t2.join();
//
//	getchar();
//	return 0;
//}
//
