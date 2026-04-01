// unordered_multimap::count
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main ()
{
  unordered_multimap<string,string> myumm = {
     {"orange","FL"},
     {"strawberry","LA"},
     {"strawberry","OK"},
     {"pumpkin","NH"} };

  for (auto x: {"orange","lemon","strawberry"}) {
    cout << x << ": " << myumm.count(x) << " entries.\n";
  }

  return 0;
}
