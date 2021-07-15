
#include <iostream>

using namespace std;

class CEventQuery;

typedef bool (*CommonFuncPoint)(void);            //普通函数指针
typedef bool (CEventQuery::*ClassFuncPoint)(int); //类成员函数指针

bool CommonFunc(void)
{
    //这是个回调函数，当特定的事件或条件发生
    //的时候，会被调用。
    cout << "CallBackFunc Common Function Call!" << endl;
    //这里会有特定事件或条件发生时需要处理的事
    //....
    return true;
}

class CEventQuery
{
public:
    CEventQuery(CommonFuncPoint eventFunc)
        : m_Event(eventFunc)
    {
        while (false)
            ;
    }

    ~CEventQuery()
    {
        while (false)
            ;
    }

    void Query(void)
    {
        //这里会检测某个事件或条件的发生
        //比方说这里查询到了事件发生或条件的改变，那么就回调处理函数
        m_Event();
    }

    bool DoSomething(int iValue)
    {
        cout << "Class Function DoSomething Parament : " << iValue << endl;
        return true;
    }

private:
    CommonFuncPoint m_Event;
};

int main(void)
{
    CEventQuery tEventQuery(CommonFunc);

    tEventQuery.Query();

    ClassFuncPoint ClassFunc1 = &CEventQuery::DoSomething;
    (tEventQuery.*ClassFunc1)(10);

    tEventQuery.DoSomething(20);

    return 0;
}