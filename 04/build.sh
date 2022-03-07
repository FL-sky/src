#!/bin/sh

set -x

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-../build} ### 如果为空就取

mkdir -p $BUILD_DIR \
  && cd $BUILD_DIR \
  && cmake $SOURCE_DIR \
  && make $* ### 还可以添加一个参数

