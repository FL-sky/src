#include "Thread.h"
#include <boost/bind.hpp>
#include <unistd.h>
#include <iostream>
using namespace std;

class Foo
{
public:
	Foo(int count) : count_(count)
	{
	}

	void MemberFun()
	{
		while (count_-- > 0)
		{
			cout << "this is a test ..." << endl;
			sleep(1);
		}
	}

	void MemberFun2(int x)
	{
		while (count_-- > 0)
		{
			cout << "x=" << x << " this is a test2 ..." << endl;
			sleep(1);
		}
	}

	int count_;
};

void ThreadFunc()
{
	cout << "ThreadFunc ..." << endl;
}

void ThreadFunc2(int count)
{
	while (count-- > 0)
	{
		cout << "ThreadFunc2 ..." << endl;
		sleep(1);
	}
}

int main(void)
{
	Thread t1(ThreadFunc);
	Thread t2(boost::bind(ThreadFunc2, 3)); ///不满足接口，利用boost::bind 接口转化
	Foo foo(5);
	Thread t3(boost::bind(&Foo::MemberFun, &foo));

	Foo foo2(3);
	Thread t4(boost::bind(&Foo::MemberFun2, &foo, 1000));

	// //Foo foo2(3);
	// Thread t4(boost::bind(&Foo::MemberFun2, &foo, 1000)); ///如果共享foo，可能会循环输出 。毕竟 while(count--);

	t1.Start();
	t2.Start();
	t3.Start();
	t4.Start();

	t1.Join();
	t2.Join();
	t3.Join();
	t4.Join();

	return 0;
}
