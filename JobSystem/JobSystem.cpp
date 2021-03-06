#include "ProducerConsumerProblem.h"
//https://mariusbancila.ro/blog/2017/01/16/dining-philosophers-in-cpp11/
//http://www.modernescpp.com/index.php/reader-writer-locks
#include "DiningPhilosopher.h"
#include "ThreadPooling.h"
#include "IJob.h"


class MyJob : public IJob
{

public:
	// Inherited via IJob
	virtual void Execute() override
	{
		cout << 1;
		this_thread::sleep_for(50ms);
	}
	virtual void Callback() override
	{
		cout << "Test \n";
	}

};
int main()
{
	ThreadPool pool{ 4 };
	MyJob job;
	while (true)
	{ 
		if (job.IsCompleted())
			auto f1 = pool.Enqueue(&job);
		pool.ExecuteCallbacks();
	}
	getchar();
	return 0;
}

