#include "ProducerConsumerProblem.h"
//https://mariusbancila.ro/blog/2017/01/16/dining-philosophers-in-cpp11/
//http://www.modernescpp.com/index.php/reader-writer-locks
#include "DiningPhilosopher.h"
#include "ThreadPooling.h"
#include "IJob.h"


class myJob : public IJob
{
public:



	// Inherited via IJob
	virtual void Execute() override
	{
		cout << 1;
	}

};
int main()
{
	//ProducerConsumerProblem pc;
	//DiningPhilosopher dp;
	//pc.ExecuteProblem();
	//dp.Init();

	{
		ThreadPool pool{ 36 };

		myJob job;

		auto f1 = pool.Enqueue(&job);
		//f1.wait();

	}
	getchar();
	return 0;
}

