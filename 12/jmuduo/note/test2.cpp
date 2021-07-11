#include <bits/stdc++.h>
using namespace std;

string demangle(const char *symbol)
{
    size_t size;
    int status;
    char temp[128];
    char *demangled;
    //first, try to demangle a c++ name
    if (1 == sscanf(symbol, "%*[^(]%*[^_]%127[^)+]", temp))
    {
        if (NULL != (demangled = abi::__cxa_demangle(temp, NULL, &size, &status)))
        {
            string result(demangled);
            free(demangled);
            return result;
        }
    }

    int main()
    {
        return 0;
    }