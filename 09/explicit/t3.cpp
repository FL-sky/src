/**
  explicit关键字的作用就是防止类构造函数的隐式自动转换.
上面也已经说过了, explicit关键字只对有一个参数的类构造函数有效, 如果类构造函数参数大于或等于两个时, 是不会产生隐式转换的, 所以explicit关键字也就无效了. 例如:  
*/

class CxString // explicit关键字在类构造函数参数大于或等于两个时无效
{
public:
    char *_pstr;
    int _age;
    int _size;
    explicit CxString(int age, int size)
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

// 这个时候有没有explicit关键字都是一样的
