#include <iostream>
#include "ArrayStack.hpp"
using namespace std;

int main() {

    ArrayStack<int> s(3);
    s.push(1);
    s.push(-67);
    s.push(34);
    cout << s << endl;

    s.pop();
    cout << s << endl;

    s.rotate(Stack<int>::RIGHT);
    cout << s << endl;

    s.rotate(Stack<int>::LEFT);
    cout << s << endl;

    ArrayStack<string> s2(3);
    s2.push("lebron");
    s2.push("jordan");
    s2.push("kobe");
    cout << s2 << endl;

    return 0;
}