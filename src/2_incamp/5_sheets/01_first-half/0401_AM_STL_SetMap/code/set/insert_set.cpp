// set::insert (C++98)
#include <iostream>
#include <set>

using namespace std;

int main ()
{
  set<int> myset;
  set<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

  it = myset.begin();
  
  myset.insert (it,25);                 
  myset.insert (it,24);                 
  myset.insert (it,26);                 

  int myints[]= {5,10,15};              // 10 already in set, not inserted
  myset.insert (myints,myints+3);

  cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}