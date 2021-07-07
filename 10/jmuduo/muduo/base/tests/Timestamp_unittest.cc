#include <muduo/base/Timestamp.h>
#include <vector>
#include <stdio.h>
#include <map>
using muduo::Timestamp;

void passByConstReference(const Timestamp &x)
{
  printf("%s\n", x.toString().c_str());
}

void passByValue(Timestamp x)
{
  printf("%s\n", x.toString().c_str());
}

void benchmark()
{
  const int kNumber = 1000 * 1000;

  std::vector<Timestamp> stamps;
  stamps.reserve(kNumber); //预留空间
  for (int i = 0; i < kNumber; ++i)
  {
    stamps.push_back(Timestamp::now());
  }
  printf("%s\n", stamps.front().toString().c_str());
  printf("%s\n", stamps.back().toString().c_str());
  printf("%f\n", timeDifference(stamps.back(), stamps.front()));

  int increments[100] = {0};
  int64_t start = stamps.front().microSecondsSinceEpoch();
  for (int i = 1; i < kNumber; ++i)
  {
    int64_t next = stamps[i].microSecondsSinceEpoch();
    int64_t inc = next - start;
    start = next;
    if (inc < 0)
    {
      printf("reverse!\n");
    }
    else if (inc < 100)
    {
      ++increments[inc];
    }
    else
    {
      printf("big gap %d\n", static_cast<int>(inc));
    }
  }

  for (int i = 0; i < 100; ++i)
  {
    printf("%2d: %d\n", i, increments[i]);
  }
}

void benchmark2()
{
  const int N = 1e3;
  const int kNumber = N * N;

  std::vector<Timestamp> stamps;
  stamps.resize(kNumber);
  for (int i = 0; i < kNumber; ++i)
  {
    stamps[i] = Timestamp::now();
  }
  printf("%s\n", stamps.front().toString().c_str());
  printf("%s\n", stamps.back().toString().c_str());
  printf("%f\n", timeDifference(stamps.back(), stamps.front()));

  std::map<int, int> increments;
  int64_t start = stamps.front().microSecondsSinceEpoch();
  for (int i = 1; i < kNumber; ++i)
  {
    int64_t next = stamps[i].microSecondsSinceEpoch();
    int64_t inc = next - start;
    start = next;
    if (inc < 0)
    {
      printf("reverse!\n");
    }
    else if (inc >= 100)
    {
      printf("big gap %d\n", static_cast<int>(inc));
    }
    ++increments[static_cast<int>(inc)];
  }

  for (std::map<int, int>::iterator it = increments.begin(); it != increments.end(); it++)
  {
    printf("%2d: %d\n", it->first, it->second);
  }
}

int main()
{
  Timestamp now(Timestamp::now());
  printf("%s\n", now.toString().c_str());
  passByValue(now);
  passByConstReference(now);
  benchmark2();
}
