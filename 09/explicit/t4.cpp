/*
但是, 也有一个例外, 就是当除了第一个参数以外的其他参数都有默认值的时候, explicit关键字依然有效, 此时, 当调用构造函数时只传入一个参数, 等效于只有一个参数的类构造函数, 例子如下:
*/

class CxString // 使用关键字explicit声明
{
public:
    int _age;
    int _size;
    explicit CxString(int age, int size = 0)
    {
        _age = age;
        _size = size;
        // 代码同上, 省略...
    }
    CxString(const char *p)
    {
        // 代码同上, 省略...
    }
};
int main()
{
    // 下面是调用:

    CxString string1(24);  // 这样是OK的
    CxString string2 = 10; // 这样是不行的, 因为explicit关键字取消了隐式转换
    CxString string3;      // 这样是不行的, 因为没有默认构造函数
    string1 = 2;           // 这样也是不行的, 因为取消了隐式转换
    string2 = 3;           // 这样也是不行的, 因为取消了隐式转换
    string3 = string1;     // 这样也是不行的, 因为取消了隐式转换, 除非类实现操作符"="的重载
    return 0;
}