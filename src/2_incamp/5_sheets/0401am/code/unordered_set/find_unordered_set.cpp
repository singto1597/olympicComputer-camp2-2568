// unordered_set::find
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main ()
{
  unordered_set<string> myset = { "red","green","blue" };

  string input;
  cout << "color? ";
  //getline (cin,input);
  cin >> input;

  unordered_set<string>::const_iterator got = myset.find (input);

  if ( got == myset.end() )
        cout << "not found in myset";
  else
        cout << *got << " is in myset";

  cout << endl;

  return 0;
}