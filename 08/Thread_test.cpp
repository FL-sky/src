#include "Thread.h"
#include <unistd.h>
#include <iostream>
using namespace std;

class TestThread : public Thread
{
public:
	TestThread(int count) : count_(count)
	{
		cout<<"TestThread ..."<<endl;
	}

	~TestThread()
	{
		cout<<"~TestThread ..."<<endl;
	}

private:
	void Run()
	{
		while (count_--)
		{
			cout<<"this is a test ..."<<endl;
			sleep(1);
		}
	}

	int count_;
};

int main(void)
{
	/*
	TestThread t(5);
	// t.run() // 这只是在主线程中执行
	t.Start();

	t.Join();///主线程结束，对象会销毁
	*/

	TestThread* t2 = new TestThread(5);
	t2->SetAutoDelete(true);
	t2->Start();///创建了一个线程，回调了 Thread::ThreadRoutine TestThread::Run
	t2->Join();

	// for (; ; )
	// 	pause();

	return 0;
}
