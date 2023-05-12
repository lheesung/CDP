#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout<<"Base Constructor"<<endl; }
    virtual void SimpleFunc() { cout<<"BaseOne"<<endl; }
};

class MiddleDrivedOne :  public Base
{
public:
    MiddleDrivedOne() : Base()
    {
        cout<<"MiddleDrivedOne Constructor"<<endl; 
    } 
    void MiddleFuncOne() 
    { 
        SimpleFunc();
        cout<<"MiddleDrivedOne"<<endl; 
    }
};

class MiddleDrivedTwo :  public Base
{
public:
    MiddleDrivedTwo() : Base()
    {
        cout<<"MiddleDrivedTwo Constructor"<<endl; 
    } 
    void MiddleFuncTwo() 
    { 
        SimpleFunc();
        cout<<"MiddleDrivedTwo"<<endl; 
    }
};

class LastDerived : public MiddleDrivedOne, public MiddleDrivedTwo
{
public:
    LastDerived() : MiddleDrivedOne(), MiddleDrivedTwo()
    {
        cout<<"LastDerived Constructor"<<endl; 
    }
    void ComplexFunc()
    {
        MiddleFuncOne();
        MiddleFuncTwo();
        SimpleFunc();
        // LastDerived 클래스가 MiddleDrivedOne 클래스와 MiddleDrivedTwo 클래스를 다중 상속하고 있기 때문에 SimpleFunc() 함수를 호출할 때 MiddleDrivedOne 클래스와 MiddleDrivedTwo 클래스 모두에서 Base 클래스를 상속받고 있는데 이 때 Base 가 2개 생기므로 문제가 된다. 이를 해결하기 위해 MiddleDrivedOne 와 MiddelDrivedTwo 에서 Base 를 상속 받을 때 virtual 키워드를 붙혀주면 문제가 해결된다.
    }
};

int main(void)
{
    LastDerived ldr;
    ldr.ComplexFunc();
    return 0;
}