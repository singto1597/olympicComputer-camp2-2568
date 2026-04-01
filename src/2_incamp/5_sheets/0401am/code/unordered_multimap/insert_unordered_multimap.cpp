// unordered_multimap::insert
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main ()
{
  unordered_multimap<string,int>
              first,
              second = {{"AAPL",200},{"GOOG",100}};

  pair<string,int> mypair ("MSFT",500);

  first.insert (mypair);                            // copy insertion
  first.insert (make_pair<string,int>("GOOG",50)); // move insertion
  first.insert (second.begin(), second.end());  // range insertion
  first.insert ( {{"ORCL",100},{"GOOG",100}} );    // initializer list insertion

  cout << "first contains:" << endl;
  for (auto x: first)
    cout << x.first << ": " << x.second << endl;

  cout << endl;
  return 0;
}
