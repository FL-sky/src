#include <muduo/base/Atomic.h>
#include <assert.h>

//raw
// int main()
// {
//   {
//     muduo::AtomicInt64 a0;
//     assert(a0.get() == 0);
//     assert(a0.getAndAdd(1) == 0);
//     assert(a0.get() == 1);
//     assert(a0.addAndGet(2) == 3);
//     assert(a0.get() == 3);
//     assert(a0.incrementAndGet() == 4);
//     assert(a0.get() == 4);
//     a0.increment();
//     assert(a0.get() == 5);
//     assert(a0.addAndGet(-3) == 2);
//     assert(a0.getAndSet(100) == 2);
//     assert(a0.get() == 100);
//   }

//   {
//     muduo::AtomicInt32 a1;
//     assert(a1.get() == 0);
//     assert(a1.getAndAdd(1) == 0);
//     assert(a1.get() == 1);
//     assert(a1.addAndGet(2) == 3);
//     assert(a1.get() == 3);
//     assert(a1.incrementAndGet() == 4);
//     assert(a1.get() == 4);
//     a1.increment();
//     assert(a1.get() == 5);
//     assert(a1.addAndGet(-3) == 2);
//     assert(a1.getAndSet(100) == 2);
//     assert(a1.get() == 100);
//   }
// }

// #include <muduo/base/BlockingQueue.h>
// #include <muduo/base/BoundedBlockingQueue.h>
// #include <muduo/base/CountDownLatch.h>
// #include <muduo/base/Mutex.h>
// #include <muduo/base/Thread.h>

// #include <muduo/base/LogStream.h>

#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <bits/stdc++.h>
using namespace std;

int idx;

struct po
{
  int id, v, w;
  po *nxt;
  po()
  {
    v = rand() % 5, w = rand() % 11;
    id = ++idx;
    nxt = NULL;
  }
  ~po()
  {
    printf("destroy id=%d\tv=%d w=%d\n", id, v, w);
  }
};
typedef boost::ptr_vector<po> ptrVp;
typedef ptrVp::auto_type poPtr;

void func1()
{
  int n = 10;
  ptrVp pvp;
  for (int i = 0; i < n; i++)
  {
    po *p = new po;
    pvp.push_back(p);
  }
}
int main()
{
  poPtr x(new po);
  cout << x->v << " " << x->w << " " << x->nxt << endl;
  return 0;
}
