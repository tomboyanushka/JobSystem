#include "ProducerConsumerProblem.h"
//https://mariusbancila.ro/blog/2017/01/16/dining-philosophers-in-cpp11/
//http://www.modernescpp.com/index.php/reader-writer-locks
#include "DiningPhilosopher.h"
#include "ThreadPooling.h"
#include "IJob.h"


class myJob : public IJob
{
public:
	float b;
	std::function<void()> callback;
	// Inherited via IJob
	virtual void Execute() override
	{
		float a = 10 * 45 + 56 / 21;
		b = a;
	}
	virtual void Callback() override
	{
		if (callback)
			callback();
	}

};
int main()
{
	{
		ThreadPool pool{ 4 };
		myJob job;
		job.Type = PERFRAMEJOB;
		job.callback = [&]
		{
			cout << job.b;
		};
		if (job.IsCompleted())
		{
			auto f1 = pool.Enqueue(&job);
		}
		
	}
	
	getchar();
	return 0;
}

