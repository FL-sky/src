#include <bits/stdc++.h>
using namespace std;

// struct po
// {
//     int x, y, z, w;
//     po(int a, int b) : x(a), y(b), z(-1), w(a + b)
//     {
//         printf("%d %d %d %d\n", x, y, z, w);
//     }
//     void output()
//     {
//         printf("%d %d %d %d\n", x, y, z, w);
//     }
// };

class po
{
public:
    po(int a, int b) : x(a), y(b), z(-1), w(a + b)
    {
        printf("%d %d %d %d\n", x, y, z, w);
    }
    void output()
    {
        printf("%d %d %d %d\n", x, y, z, w);
    }

private:
    int x, y, z, w;
};
int main()
{
    po tp(1, 2); ////观察输出可得，先（参数）初始化列表
    tp.output();
    return 0;
}