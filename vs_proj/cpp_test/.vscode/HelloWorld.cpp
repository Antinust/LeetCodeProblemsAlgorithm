#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base1
{
public:
    int base1_1;
    int base1_2;

    virtual void vf1() {}
    virtual void vf2() {}
};

class Base2
{
public:
    int base2_1;
    int base2_2;

    virtual void b2_vf1() {}
    virtual void b2_vf2() {}
};

// 多继承
class Derive1 : public Base1, public Base2
{
public:
    int derive1_1;
    int derive1_2;

    // 基类虚函数覆盖
    virtual void vf1() {}
    virtual void b2_vf2() {}

    // 自身定义的虚函数
    virtual void d_vf1() {}
    virtual void d_vf2() {}
};

int main()
{
    Derive1 d1;
    Derive1* pd1 = &d1;
    pd1->d_vf2();

    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    cout << msg.size() << " ";
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}