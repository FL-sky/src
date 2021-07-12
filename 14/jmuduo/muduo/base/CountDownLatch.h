// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_COUNTDOWNLATCH_H
#define MUDUO_BASE_COUNTDOWNLATCH_H

#include <muduo/base/Condition.h>
#include <muduo/base/Mutex.h>

#include <boost/noncopyable.hpp>

namespace muduo
{

  class CountDownLatch : boost::noncopyable
  {
  public:
    explicit CountDownLatch(int count);
    /*
explicit关键字的作用就是防止类构造函数的隐式自动转换.

explicit关键字只对有一个参数的类构造函数有效, 如果类构造函数参数大于或等于两个时, 是不会产生隐式转换的, 所以explicit关键字也就无效了

但是, 也有一个例外, 就是当除了第一个参数以外的其他参数都有默认值的时候, explicit关键字依然有效, 此时, 当调用构造函数时只传入一个参数, 等效于只有一个参数的类构造函数
*/
    void wait();

    void countDown();

    int getCount() const;

  private:
    mutable MutexLock mutex_; //mutable 可修改;如果有const修饰，则非mutable的变量不可修改
    Condition condition_;
    int count_;
  };

}
#endif // MUDUO_BASE_COUNTDOWNLATCH_H
