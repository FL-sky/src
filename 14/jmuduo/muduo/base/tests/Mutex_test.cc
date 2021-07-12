//#include <muduo/base/CountDownLatch.h>
#include <muduo/base/Mutex.h>
#include <muduo/base/Thread.h>
#include <muduo/base/Timestamp.h>

#include <boost/bind.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <vector>
#include <stdio.h>

using namespace muduo;
using namespace std;

MutexLock g_mutex;
vector<int> g_vec;
const int kCount = 10 * 1000 * 1000;

void threadFunc()
{
  for (int i = 0; i < kCount; ++i)
  {
    MutexLockGuard lock(g_mutex);
    g_vec.push_back(i);
  }
}

int xmain()
{
  const int kMaxThreads = 8;
  g_vec.reserve(kMaxThreads * kCount);

  Timestamp start(Timestamp::now());
  for (int i = 0; i < kCount; ++i)
  {
    g_vec.push_back(i);
  }
  double zt = timeDifference(Timestamp::now(), start);
  printf("single thread without lock %f\n", zt);

  start = Timestamp::now();
  threadFunc();
  zt = timeDifference(Timestamp::now(), start);
  printf("single thread with lock %f\n", zt);

  for (int nthreads = 1; nthreads < kMaxThreads; ++nthreads)
  {
    boost::ptr_vector<Thread> threads;
    g_vec.clear();
    start = Timestamp::now();
    for (int i = 0; i < nthreads; ++i)
    {
      threads.push_back(new Thread(&threadFunc));
      threads.back().start();
    }
    for (int i = 0; i < nthreads; ++i)
    {
      threads[i].join();
    }
    zt = timeDifference(Timestamp::now(), start);
    printf("%d thread(s) with lock %f\n", nthreads, zt);
  }
  return 0;
}

#include <stdlib.h>
int main(int argc, char *argv[])
{

  boost::ptr_vector<Thread> threads;
  g_vec.clear();
  int nthreads = atoi(argv[1]);
  Timestamp start = Timestamp::now();
  for (int i = 0; i < nthreads; ++i)
  {
    threads.push_back(new Thread(&threadFunc));
    threads.back().start();
  }
  for (int i = 0; i < nthreads; ++i)
  {
    threads[i].join();
  }
  double zt = timeDifference(Timestamp::now(), start);
  printf("%d thread(s) with lock %f\n", nthreads, zt);
  return 0;
}
