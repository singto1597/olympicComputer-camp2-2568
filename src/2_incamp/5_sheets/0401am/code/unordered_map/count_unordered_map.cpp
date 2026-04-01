// unordered_map::count
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main ()
{
  unordered_map<string,double> mymap = {
     {"Burger",2.99},
     {"Fries",1.99},
     {"Soda",1.50} };

  for (auto& x: {"Burger","Pizza","Salad","Soda"}) {
    if (mymap.count(x)>0)
      cout << "mymap has " << x << endl;
    else
      cout << "mymap has no " << x << endl;
  }

  return 0;
}
