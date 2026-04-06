// unordered_multimap::erase
#include <iostream>
#include <unordered_map>

using namespace std;

int main ()
{
  unordered_multimap<string,string> myumm = {
         {"strawberry","red"},
         {"banana","yellow"},
         {"orange","orange"},
         {"lemon","yellow"},
         {"apple","red"},
         {"apple","green"},
         {"pear","green"},
  };


  // erase examples:
  myumm.erase ( myumm.begin() );     // erasing by iterator
  myumm.erase ("apple");             // erasing by key (erases 2 elements)
  myumm.erase ( myumm.find("orange"), myumm.end() ); // erasing by range

  // show content:
  for ( auto x: myumm )
    cout << x.first << ": " << x.second << endl;

  return 0;
}
