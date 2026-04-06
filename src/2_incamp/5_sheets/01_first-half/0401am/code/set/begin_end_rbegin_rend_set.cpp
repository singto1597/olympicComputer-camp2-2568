// set::begin/end
#include <iostream>
#include <set>

using namespace std;

int main ()
{
  int myints[] = {75,23,65,42,13};
  set<int> myset (myints,myints+5);

  cout << "myset contains (forward):";
  for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    cout << ' ' << *it;

  cout << '\n';
  
  cout << "myset contains (backward):";
  for (set<int>::reverse_iterator it=myset.rbegin(); it!=myset.rend(); ++it)
    cout << ' ' << *it;

  return 0;
}