// multimap::lower_bound/upper_bound
#include <iostream>
#include <map>

using namespace std;

int main ()
{
  multimap<char,int> mymultimap;
  multimap<char,int>::iterator it,itlow,itup;

  mymultimap.insert(make_pair('a',10));
  mymultimap.insert(make_pair('b',121));
  mymultimap.insert(make_pair('c',1001));
  mymultimap.insert(make_pair('c',2002));
  mymultimap.insert(make_pair('d',11011));
  mymultimap.insert(make_pair('e',44));

  itlow = mymultimap.lower_bound ('b');  // itlow points to b
  itup = mymultimap.upper_bound ('d');   // itup points to e (not d)

  // print range [itlow,itup):
  for (it=itlow; it!=itup; ++it)
    cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}
