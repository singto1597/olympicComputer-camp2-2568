// map::insert (C++98)
#include <iostream>
#include <map>

using namespace std;

int main ()
{
  map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( pair<char,int>('a',100) );
  mymap.insert ( pair<char,int>('z',200) );
  mymap.insert ({'d', 600});

  // second insert function version (with hint position):
  map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, pair<char,int>('b',300));
  mymap.insert (it, pair<char,int>('c',400));
  mymap.insert (it, {'e', 550});

  // third insert function version (range insertion):
  map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('e'));

  // showing contents:
  cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    cout << it->first << " => " << it->second << '\n';

  cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    cout << it->first << " => " << it->second << '\n';

  return 0;
}