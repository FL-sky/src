#include <bits/stdc++.h>
using namespace std;

void fv(int &x, int y)
{
    x += y;
}

int getfv(int &x, int y)
{
    return fv(x, y); ///返回值类型与函数类型不匹配C/C++(120)
}
int main()
{

    return 0;
}