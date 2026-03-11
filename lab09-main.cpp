#include <iostream>
#include "ArrayStack.hpp"
using namespace std;

int main() {

    ArrayStack<int> s(3);           // ints
    cout << "Push stuff\n";
    s.push(1);
    s.push(-67);          //puush
    s.push(34);
    cout << s << endl;
    cout << "Peek: " << s.peek() << endl;
    s.pop();
    cout << "After pop:\n";
    cout << s << endl;
    cout << "Before rotate:\n";
    cout << s << endl;
    s.rotate(Stack<int>::RIGHT);
    cout << "After R rotate:\n";
    cout << s << endl;
    s.rotate(Stack<int>::LEFT);
    cout << "After L rotate:\n";
    cout << s << endl;
    cout << "\nString stack\n";

    ArrayStack<string> s2(3);               // strings
    s2.push("lebron");
    s2.push("jordan");          // add and then print to show it works
    s2.push("kobe");
    cout << s2 << endl;
    return 0;
}