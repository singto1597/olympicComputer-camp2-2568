// C++ program to illustrate
// unordered_set operator!= 
 
#include <cstring>
#include <iostream>
#include <unordered_set>
using namespace std;
 
int main()
{
    unordered_set<string>
        a = { "C++", "Java", "Python" },
        b = { "Java", "Python", "C++" },
        c = { "C#", "Python", "Java" };
 
    if (a == b) {
        cout << "a and b are equal\n";
    }
    else {
        cout << "a and b are not equal\n";
    }
 
    if (a != c) {
        cout << "a and c are not equal\n";
    }
    else {
        cout << "a and c are equal\n";
    }
 
    return 0;
}