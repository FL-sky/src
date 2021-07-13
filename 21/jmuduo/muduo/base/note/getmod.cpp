#include <bits/stdc++.h>
using namespace std;

template <typename T>
size_t convert(char buf[], T value)
{
    int sign = 1;
    if (value < 0)
    {
        sign = -1;
        value = -value;
    }
    int len = 0;
    do
    {
        buf[len++] = value % 10 + '0';
        value /= 10;
    } while (value);

    if (sign == -1)
    {
        buf[len++] = '-';
    }
    buf[len] = '\0';
    //std::reverse(buf, p);
    for (int i = 0, up = len >> 1; i < up; i++)
    {
        char tmp = buf[i];
        buf[i] = buf[len - 1 - i];
        buf[len - 1 - i] = tmp;
    }

    return len;
}

void gtmd()
{
    int x, y;
    while (cin >> x >> y)
    {
        cout << x % y << endl;
    }
}
int main()
{
    char buf[128];
    size_t sz = convert(buf, 1);
    cout << buf << endl
         << sz << endl;
    return 0;
}