#include "ProducerConsumerProblem.h"
//https://mariusbancila.ro/blog/2017/01/16/dining-philosophers-in-cpp11/
//http://www.modernescpp.com/index.php/reader-writer-locks
#include "DiningPhilosopher.h"
#include "ThreadPooling.h"


int main()
{
	//ProducerConsumerProblem pc;
	//DiningPhilosopher dp;
	//pc.ExecuteProblem();
	//dp.Init();

	ThreadPool pool{ 36 };

	getchar();
	return 0;
}

