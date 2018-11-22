#pragma once
#include <mutex>
#include <future>
enum JobType
{
	PERFRAMEJOB,
	NonPERFRAMEJOB

};
class IJob
{

public:
	virtual void Execute() {};
	virtual void Callback() {};
	void SetIsCompleted(bool value);
	bool IsCompleted();
	bool mIsCompleted = true;
	JobType Type = PERFRAMEJOB;
	std::mutex mutex;
};