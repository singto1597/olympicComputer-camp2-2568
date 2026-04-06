// unordered_map::insert
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main ()
{
  unordered_map<string,double>
              myrecipe,
              mypantry = {{"milk",2.0},{"flour",1.5}};

  pair<string,double> myshopping ("baking powder",0.3);

  myrecipe.insert (myshopping);                        // copy insertion
  myrecipe.insert (make_pair<string,double>("eggs",6.0)); // move insertion
  myrecipe.insert (mypantry.begin(), mypantry.end());  // range insertion
  myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );    // initializer list insertion

  cout << "myrecipe contains:" << endl;
  for (auto x: myrecipe)
    cout << x.first << ": " << x.second << std::endl;

  cout << endl;
  return 0;
}
