// unordered_set::erase
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main ()
{
  unordered_set<string> myset =
  {"USA","Canada","France","UK","Japan","Germany","Italy"};
  
  cout << "myset contains:";
  for ( const string& x: myset ) 
     cout << " " << x;

  myset.erase ( myset.begin() );                    // erasing by iterator
  cout << "\nmyset contains:";
  for ( const string& x: myset ) 
     cout << " " << x;
  myset.erase ( "France" );                         // erasing by key
  myset.erase ( myset.find("Japan"), myset.end() ); // erasing by range

  cout << "\nmyset contains:";
  for ( const string& x: myset ) 
     cout << " " << x;
  
  return 0;
}