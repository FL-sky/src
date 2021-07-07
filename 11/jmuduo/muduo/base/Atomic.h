// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_ATOMIC_H
#define MUDUO_BASE_ATOMIC_H

#include <boost/noncopyable.hpp>
#include <stdint.h>

namespace muduo
{

  namespace detail
  {
    template <typename T>
    class AtomicIntegerT : boost::noncopyable
    {
    public:
      AtomicIntegerT()
          : value_(0)
      {
      }

      // uncomment if you need copying and assignment
      //
      // AtomicIntegerT(const AtomicIntegerT& that)
      //   : value_(that.get())
      // {}
      //
      // AtomicIntegerT& operator=(const AtomicIntegerT& that)
      // {
      //   getAndSet(that.get());
      //   return *this;
      // }

      T get()
      {
        ///比较和设置操作
        return __sync_val_compare_and_swap(&value_, 0, 0);
        //如果value==0,则设置value的值为0
        //如果value！=0,则返回value的值 //都是返回修改之前的值
      }

      T getAndAdd(T x)
      {
        return __sync_fetch_and_add(&value_, x);
      }

      T addAndGet(T x)
      {
        return getAndAdd(x) + x;
      }

      T incrementAndGet()
      {
        return addAndGet(1);
      }

      T decrementAndGet()
      {
        return addAndGet(-1);
      }

      void add(T x)
      {
        getAndAdd(x);
      }

      void increment()
      {
        incrementAndGet();
      }

      void decrement()
      {
        decrementAndGet();
      }

      T getAndSet(T newValue)
      {
        return __sync_lock_test_and_set(&value_, newValue);
      }

    private:
      volatile T value_;
      /*
  volatile是一个特征修饰符（type specifier）.volatile的作用是作为指令关键字，确保本条指令不会因编译器的优化而省略，且要求每次直接读值。
volatile的变量是说这变量可能会被意想不到地改变，这样，编译器就不会去假设这个变量的值了。
  */
    };
  }

  typedef detail::AtomicIntegerT<int32_t> AtomicInt32;
  typedef detail::AtomicIntegerT<int64_t> AtomicInt64;
}

#endif // MUDUO_BASE_ATOMIC_H
