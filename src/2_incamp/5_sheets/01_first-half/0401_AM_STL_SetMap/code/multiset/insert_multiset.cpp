// multiset::insert (C++98)
#include <iostream>
#include <set>

using namespace std;

int main ()
{
  multiset<int> mymultiset;

  // set some initial values:
  for (int i=1; i<=5; i++){
    mymultiset.insert(i*10);  // 10 20 30 40 50
  }

  mymultiset.insert(15);

  int myints[]= {5,10,15};
  mymultiset.insert (myints,myints+3);

  cout << "mymultiset contains:";
  for (auto i: mymultiset)
    cout << i << ' ';

  return 0;
}
