// erasing from multiset
#include <iostream>
#include <set>

using namespace std;

int main ()
{
  multiset<int> mymultiset;

  // insert some values:
  mymultiset.insert (40);                            // 40
   mymultiset.insert (40);                           // 40 40
  for (int i=1; i<7; i++){
    mymultiset.insert(i*10);   // 10 20 30 40 40 40 50 60
  }

  cout << "mymultiset contains:";
  for (auto i:mymultiset){
     cout << i << " ";
  }

  mymultiset.erase (40);                             // 10 30 50 60

  cout << "\nmymultiset contains:";
  for (auto i:mymultiset){
     cout << i << " ";
  }

  return 0;
}
