#include <iostream>
#include <boost/function.hpp>

using namespace std;

template <typename Func>
class CFuncDemo
{
public:
    CFuncDemo(int iValue)
        : m_iValue(iValue)
    {
        while (false)
            ;
    }

    template <typename CallBackFunc>
    void acceptFunc(CallBackFunc _Func)
    {
        m_Func = _Func;
    }

    void CommonResult()
    {
        m_Func(m_iValue);
    }

    template <typename T>
    void ClassMemberResult(T &t)
    {
        m_Func(t, m_iValue);
        //m_Func(m_iValue); ///error: no match for call to ‘(boost::function<void(CMultiple&, int)>) (int&)’
    }

    void FuncObjResult()
    {
        m_Func(m_iValue);
    }

private:
    Func m_Func;
    int m_iValue;
};

//普通函数
void CommonFunc(int iValue)
{
    cout << "CallBack Common Function" << endl;
    cout << "2 * iValue = " << 2 * iValue << endl;
}

//这个类有个成员函数完成类似的功能
class CMultiple
{
public:
    void ClassFunc(int iValue)
    {
        cout << "CallBack Class Member Function" << endl;
        cout << "3 * iValue = " << 3 * iValue << endl;
    }
};

//这里有个函数对象同样也完成对应的功能
class CFuncObj
{
public:
    void operator()(int iValue)
    {
        cout << "CallBack Function Object" << endl;
        cout << "4 * iValue = " << 4 * iValue << endl;
    }
};

int main(void)
{
    //作为示范的测试用例，这里我们展示了：普通函数、类成员函数、函数对象的使用

    //普通函数
    CFuncDemo<boost::function<void(int)>> tFuncCommon(10);
    tFuncCommon.acceptFunc(CommonFunc);
    tFuncCommon.CommonResult();

    //类成员函数
    CMultiple tMember;
    CFuncDemo<boost::function<void(CMultiple &, int)>> tFuncClassMember(10);
    tFuncClassMember.acceptFunc(&CMultiple::ClassFunc);
    tFuncClassMember.ClassMemberResult(tMember);

    //函数对象
    CFuncObj tObj;
    CFuncDemo<boost::function<void(int)>> tFuncObj(10);
    //tFuncObj.acceptFunc(tObj);
    //function使用拷贝语义保存参数，使用ref它允许以引用的方式传递参数
    tFuncObj.acceptFunc(boost::ref(tObj));
    tFuncObj.FuncObjResult();

    return 0;
}

// template <typename T>
// void ClassMemberResult(T &t)
// {
//     CMultiple::ClassFunc(t, 9);
// }

// int main()
// {
//     CMultiple tMember;
//     ClassMemberResult(tMember);
//     return 0;
// }