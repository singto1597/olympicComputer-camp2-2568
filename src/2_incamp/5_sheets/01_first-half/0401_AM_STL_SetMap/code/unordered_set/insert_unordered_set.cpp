 // unordered_set::insert
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main ()
{
  unordered_set<string> myset = {"green","blue","yellow"};
  cout << "myset contains (initial):";
  for (auto i:myset){
      cout << i << " ";
  }
  cout << endl;

  string mystring = "red";

  myset.insert (mystring); // copy insertion
  cout << "myset contains (after insert mystring):";
  for (auto i:myset){
      cout << i << " ";
  }
  cout << endl;

  myset.insert (mystring+"dish");                 // move insertion
  cout << "myset contains (after insert concatenation):";
  for (auto i:myset){
      cout << i << " ";
  }
  cout << endl;

  myset.insert ( {"purple","orange"} );           // initializer list insertion

  cout << "myset contains (after insert purple&orange):";
  for (auto i:myset){
      cout << i << " ";
  }
  return 0;
}
