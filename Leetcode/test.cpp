#include<iostream>
using namespace std;

class A {
public:
    void f1(int a) {
        cout << "A" << endl;
    }

};

class B : public A {
public:
    void f1() {
        cout << "B" << endl;
    }
};

int main() {
    A a;
    a.f1(1);

    B b;
    b.f1();
    b.f1(1);
}
