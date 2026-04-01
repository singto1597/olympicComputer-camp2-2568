// erasing from multimap
#include <iostream>
#include <map>

using namespace std;

int main ()
{
  multimap<char,int> mymultimap;

  // insert some values:
  mymultimap.insert(pair<char,int>('a',10));
  mymultimap.insert(pair<char,int>('b',20));
  mymultimap.insert(pair<char,int>('b',30));
  mymultimap.insert(pair<char,int>('c',40));
  mymultimap.insert(pair<char,int>('d',50));
  mymultimap.insert(pair<char,int>('d',60));
  mymultimap.insert(pair<char,int>('e',70));
  mymultimap.insert(pair<char,int>('f',80));

  multimap<char,int>::iterator it = mymultimap.find('b');

  mymultimap.erase (it);                     // erasing by iterator (1 element)

  mymultimap.erase ('d');                    // erasing by key (2 elements)

  it=mymultimap.find ('e');
  mymultimap.erase ( it, mymultimap.end() ); // erasing by range

  // show content:
  for (it=mymultimap.begin(); it!=mymultimap.end(); ++it)
    cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}
