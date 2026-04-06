// multimap::find
#include <iostream>
#include <map>

using namespace std;

int main ()
{
  multimap<char,int> mymm;

  mymm.insert (make_pair('x',10));
  mymm.insert (make_pair('y',20));
  mymm.insert (make_pair('z',30));
  mymm.insert (make_pair('z',40));
  mymm.insert ({'x',5});
  mymm.insert ({'y',15});

  cout << "element in mymm: \n";

  for(auto i:mymm){
      cout << i.first << " => " << i.second << " ";
      cout << endl;
  }

  multimap<char,int>::iterator it = mymm.find('x');
  mymm.erase (it);
  mymm.erase (mymm.find('z'));

  // print content:
  cout << "\nelements in mymm:" << '\n';
  cout << "y => " << mymm.find('y')->second << '\n';
  cout << "z => " << mymm.find('z')->second << '\n';

  return 0;
}
