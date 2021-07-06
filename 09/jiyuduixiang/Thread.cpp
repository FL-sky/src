#include "Thread.h"
#include <iostream>
using namespace std;

Thread::Thread(const ThreadFunc &func) : func_(func), autoDelete_(false)
{
	while (false)
		;
}

void Thread::Start()
{
	pthread_create(&threadId_, NULL, ThreadRoutine, this);
}

void Thread::Join()
{
	pthread_join(threadId_, NULL);
}

void *Thread::ThreadRoutine(void *arg)
{
	Thread *thread = static_cast<Thread *>(arg);
	/* https://baike.baidu.com/item/static_cast/4472966?fr=aladdin
	static_cast <type-id>( expression )
	该运算符把expression转换为type-id类型，但没有运行时类型检查来保证转换的安全性。它主要有如下几种用途：...
	*/
	thread->Run();
	if (thread->autoDelete_)
		delete thread;
	return NULL;
}

void Thread::SetAutoDelete(bool autoDelete)
{
	autoDelete_ = autoDelete;
}

void Thread::Run()
{
	func_();
}
