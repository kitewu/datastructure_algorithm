#include <iostream>
using namespace std;
class P
{
public :
    virtual void print()
    {
        cout << "A" << endl;
    }
};
class S:  public P
{
public :
    void print()
    {
        cout << "B" << endl;
    }
};
int main()
{
    P* a = new S();
    a->print();
}
