// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_SINGLETON_H
#define MUDUO_BASE_SINGLETON_H

#include <boost/noncopyable.hpp>
#include <pthread.h>
#include <stdlib.h> // atexit

namespace muduo
{

  template <typename T>
  class Singleton : boost::noncopyable
  {
  public:
    static T &instance()
    {
      pthread_once(&ponce_, &Singleton::init);
      return *value_;
    }

  private:
    Singleton();
    ~Singleton();

    static void init()
    {
      value_ = new T();
      ::atexit(destroy); ///注册一个销毁函数
    }

    static void destroy()
    {
      typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1]; ///在编译阶段发现错误
      delete value_;
    }

  private:
    static pthread_once_t ponce_;
    static T *value_;
  };

  template <typename T>
  pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

  template <typename T>
  T *Singleton<T>::value_ = NULL;

}
#endif

/*
解决办法：defined but not used [-Werror=unused-variable]

遇到错误如下：
/grpc/gens/src/proto/grpc/core/stats.pb.cc:187:13: error: ‘dynamic_init_dummy_src_2fproto_2fgrpc_2fcore_2fstats_2eproto’ defined but not used [-Werror=unused-variable]
 static bool dynamic_init_dummy_src_2fproto_2fgrpc_2fcore_2fstats_2eproto = []()
             ^
cc1plus: all warnings being treated as errors


找到Makefile，去掉其中-Werror ，重新编译。


*/