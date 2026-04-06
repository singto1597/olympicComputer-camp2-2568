// multimap::count
#include <iostream>
#include <map>

using namespace std;

int main ()
{
  multimap<char,int> mymm;

  mymm.insert(make_pair('x',50));
  mymm.insert(make_pair('y',100));
  mymm.insert(make_pair('y',150));
  mymm.insert(make_pair('y',200));
  mymm.insert(make_pair('z',250));
  mymm.insert(make_pair('z',300));

  for (char c='x'; c<='z'; c++)
  {
    cout << "There are " << mymm.count(c) << " elements with key " << c << ":";
    multimap<char,int>::iterator it;
    for (it=mymm.equal_range(c).first; it!=mymm.equal_range(c).second; ++it)
      cout << ' ' << (*it).second;
    cout << '\n';
  }

  return 0;
}
