// unordered_multiset::insert
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main ()
{
  unordered_multiset<string> myums = {"red","green","blue"};
  string mystring = "red";

  myums.insert (mystring);                        // copy insertion
  myums.insert (mystring+"dish");                 // move insertion
  myums.insert ( {"purple","orange"} );           // initializer list insertion

  cout << "myums contains:";
  for (auto i: myums){
      cout << i << " ";
  }

  return 0;
}
