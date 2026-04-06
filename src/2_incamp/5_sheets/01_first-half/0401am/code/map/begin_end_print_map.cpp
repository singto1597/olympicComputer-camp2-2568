// Demonstrates begin() and end()
#include <iostream>
#include <map>
#include <iterator>

using namespace std;
 
int main()
{
    // declaration of map container
    map<char, int> mymap;
    mymap['a'] = 1;
    mymap['b'] = 2;
    mymap['c'] = 3;
 
    map<char, int>::iterator it;
    
    // using begin() to print map
    for (it = mymap.begin();
         it != mymap.end(); ++it)
        cout << it->first << " = "
             << it->second << '\n';
             
    for(auto &x:mymap){
        cout << x.first << " = " << x.second << endl;   
    }
    return 0;
}