#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <boost/function.hpp>

class Thread
{
public:
	typedef boost::function<void()> ThreadFunc;
	explicit Thread(const ThreadFunc &func);
	/* https://blog.csdn.net/guoyunfei123/article/details/89003369
	C++中的explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).
	*/

	void Start();
	void Join();

	void SetAutoDelete(bool autoDelete);

private:
	static void *ThreadRoutine(void *arg);
	void Run();
	ThreadFunc func_;
	pthread_t threadId_;
	bool autoDelete_;
};

#endif // _THREAD_H_
