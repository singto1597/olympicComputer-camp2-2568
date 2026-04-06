// unordered_multimap::find
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main ()
{
  unordered_multimap<string,string> mymap = {
     {"mom","college"},
     {"mom","church"},
     {"dad","office"},
     {"bro","school"} };

  cout << "one of the values for 'mom' is: ";
  cout << mymap.find("mom")->second;
  cout << endl;

  return 0;
}
