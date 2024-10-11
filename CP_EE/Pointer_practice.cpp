#include <iostream>
using namespace std;

int main() {
    int a = 123;
    cout << "The value of a is " << a << endl;
    int *p1, *p2;
    p1 = &a;
    cout << "Let p1 points to a, the address p1 has is " << p1 << endl;
    p2 = &a;
    cout << "Let p2 points to a, the address p2 has is " << p2 << endl;
    cout << "Dereferencing p1 results in " << *p1 << endl;
    cout << "Dereferencing p2 results in " << *p2 << endl;

    cout << "Now we change a by a = 456;" << endl;
    a = 456;
    cout << "a becomes " << a << endl;
    cout << "deferencing p1 reults in " << *p1 << endl;
    cout << "deferencing p2 reults in " << *p2 << endl;

    cout << "Now we change a by *p1 = 789;" << endl;
    *p1 = 789;
    cout << "a becomes " << a << endl;
    cout << "*p1 becomes " << *p1 << endl;
    cout << "*p2 becomes " << *p2 << endl;

    cout << "Let b be 321, let p1 points to b" << endl;
    int b = 321;
    p1 = &b;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "p1 is " << p1 << endl;
    cout << "p2 is " << p2 << endl;
    cout << "*p1 is " << *p1 << endl;
    cout << "*p2 is " << *p2 << endl;

    cout << "Now change *p1 to 654 and *p2 to 987;" << endl;
    *p1 = 654, *p2 = 987;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "p1 is " << p1 << endl;
    cout << "p2 is " << p2 << endl;
    cout << "*p1 is " << *p1 << endl;
    cout << "*p2 is " << *p2 << endl;

    cout << "Let pp3 be a pointer to pointer to int" << endl;
    int **pp3;
    cout << "Let pp3 point to p1" << endl;
    pp3 = &p1;
    cout << "pp3, *pp3, and **pp3 are " << pp3 << ", " << *pp3 << ", and " << **pp3 << endl;
    cout << "Assign 123456 to **pp3" << endl;
    **pp3 = 123456;
    cout << "a and b becomes " << a << " and " << b << endl;
    cout << "Let *pp3 be p2" << endl;
    *pp3 = p2;
    cout << "p1 and p2 are " << p1 << " and " << p2 << endl;
    cout << "Assign 654321 to **pp3" << endl;
    **pp3 = 654321;
    cout << "a and b becomes " << a << " and " << b << endl;
}
