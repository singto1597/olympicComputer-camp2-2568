// map::rbegin/rend
#include <iostream>
#include <map>

using namespace std;

int main ()
{
  map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  cout << "backwards\n";
  map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    cout << rit->first << " => " << rit->second << '\n';
    
  cout << "forwards\n";
  map<char,int>::iterator it;
  for(it=mymap.begin(); it!=mymap.end(); ++it)
    cout << it->first << " => " << it->second << '\n';

  return 0;
}