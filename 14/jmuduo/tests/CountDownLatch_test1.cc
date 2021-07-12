#include <muduo/base/CountDownLatch.h>
#include <muduo/base/Thread.h>

#include <boost/bind.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <string>
#include <stdio.h>

using namespace muduo;

class Test
{
public:
  Test(int numThreads)
      : latch_(1),
        threads_(numThreads)
  {
    for (int i = 0; i < numThreads; ++i)
    {
      char name[32];
      snprintf(name, sizeof name, "work thread %d", i);
      threads_.push_back(new muduo::Thread(
          boost::bind(&Test::threadFunc, this), muduo::string(name)));
    }
    for_each(threads_.begin(), threads_.end(), boost::bind(&Thread::start, _1));
  }

  void run()
  {
    latch_.countDown();
  }

  void joinAll()
  {
    for_each(threads_.begin(), threads_.end(), boost::bind(&Thread::join, _1));
  }

private:
  void threadFunc()
  {
    latch_.wait();
    printf("tid=%d, %s started\n",
           CurrentThread::tid(),
           CurrentThread::name());

    printf("tid=%d, %s stopped\n",
           CurrentThread::tid(),
           CurrentThread::name());
  }

  CountDownLatch latch_;
  boost::ptr_vector<Thread> threads_;
};

int xmain()
{
  printf("pid=%d, tid=%d\n", ::getpid(), CurrentThread::tid());
  Test t(3);
  sleep(3);
  printf("pid=%d, tid=%d %s running ...\n", ::getpid(), CurrentThread::tid(), CurrentThread::name());
  t.run();
  t.joinAll();

  printf("number of created threads %d\n", Thread::numCreated());

  return 0;
}

#include <vector>
void func(int x)
{
  printf("x=%d\n", x);
}

void func2(int x = 0)
{
  printf("hello\n");
}

int main()
{
  puts("----------------");
  std::vector<int> v = {2, 3, 5, 7, 11};
  for_each(v.begin(), v.end(), boost::bind(func, _1));
  for_each(v.begin(), v.end(), func2); //func2至少要有1个形参
  return 0;
}