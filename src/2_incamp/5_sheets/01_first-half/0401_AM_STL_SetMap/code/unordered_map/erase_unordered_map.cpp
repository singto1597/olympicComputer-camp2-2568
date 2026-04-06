// unordered_map::erase
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main ()
{
  unordered_map<string,string> mymap;

  // populating container:
  mymap["U.S."] = "Washington";
  mymap["U.K."] = "London";
  mymap["France"] = "Paris";
  mymap["Russia"] = "Moscow";
  mymap["China"] = "Beijing";
  mymap["Germany"] = "Berlin";
  mymap["Japan"] = "Tokyo";

  cout << endl << "mymap begin " << endl;
  for ( auto& x: mymap )
    cout << x.first << ": " << x.second << endl;

  // erase examples:
  mymap.erase ( mymap.begin() );      // erasing by iterator

  // show content:
  cout << endl << "after delete mymap.begin(): " << endl;
  for ( auto& x: mymap )
    cout << x.first << ": " << x.second << endl;

  mymap.erase ("France");             // erasing by key

  cout << endl << "after delete France " << endl;
  // show content:
  for ( auto& x: mymap )
    cout << x.first << ": " << x.second << endl;

  cout << endl << "after delete from Chaina " << endl;

  mymap.erase ( mymap.find("China"), mymap.end() ); // erasing by range

  // show content:
  for ( auto& x: mymap )
    cout << x.first << ": " << x.second << endl;

  return 0;
}
