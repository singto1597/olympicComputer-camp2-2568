// assignment operator with multimaps
#include <iostream>
#include <map>

using namespace std;

int main ()
{
  multimap<char,int> foo,bar;

  foo.insert(make_pair('x',32));
  foo.insert(make_pair('y',64));
  foo.insert(make_pair('y',96));
  foo.insert(make_pair('z',128));

  bar = foo;                  // bar now contains 4 ints
  foo.clear();                // and first is now empty

  cout << "Size of foo: " << foo.size() << '\n';
  cout << "Size of bar: " << bar.size() << '\n';
  return 0;
}
