
class CxString // 没有使用explicit关键字的类声明, 即默认为隐式声明
{
public:
    char *_pstr;
    int _size;
    CxString(int size)
    {
        _size = size;             // string的预设大小
        _pstr = malloc(size + 1); // 分配string的内存
        memset(_pstr, 0, size + 1);
    }
    CxString(const char *p)
    {
        int size = strlen(p);
        _pstr = malloc(size + 1); // 分配string的内存
        strcpy(_pstr, p);         // 复制字符串
        _size = strlen(_pstr);
    }
    // 析构函数这里不讨论, 省略...
};

// 下面是调用:
int main()
{

    CxString string1(24);     // 这样是OK的, 为CxString预分配24字节的大小的内存
    CxString string2 = 10;    // 这样是OK的, 为CxString预分配10字节的大小的内存
    CxString string3;         // 这样是不行的, 因为没有默认构造函数, 错误为: “CxString”: 没有合适的默认构造函数可用
    CxString string4("aaaa"); // 这样是OK的
    CxString string5 = "bbb"; // 这样也是OK的, 调用的是CxString(const char *p)
    CxString string6 = 'c';   // 这样也是OK的, 其实调用的是CxString(int size), 且size等于'c'的ascii码
    string1 = 2;              // 这样也是OK的, 为CxString预分配2字节的大小的内存
    string2 = 3;              // 这样也是OK的, 为CxString预分配3字节的大小的内存
    string3 = string1;        // 这样也是OK的, 至少编译是没问题的, 但是如果析构函数里用free释放_pstr内存指针的时候可能会报错, 完整的代码必须重载运算符"=", 并在其中处理内存释放
    return 0;
}

//上面的代码中, "CxString string2 = 10;" 这句为什么是可以的呢 ? 在C++ 中, 如果的构造函数只有一个参数时, 那么在编译的时候就会有一个缺省的转换操作 :
//将该构造函数对应数据类型的数据转换为该类对象.也就是说 "CxString string2 = 10;" 这段代码, 编译器自动将整型转换为CxString类对象, 实际上等同于下面的操作:

void ex1()
{

    CxString string2(10);
    //或
    CxString temp(10);
    CxString string2 = temp;
}