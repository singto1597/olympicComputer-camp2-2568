// unordered_set::bucket
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main ()
{
  unordered_set<string> myset = {"water","sand","ice","foam"};

  for (auto x: myset) {
    cout << x << " is in bucket #" << myset.bucket(x) << endl;
  }

  return 0;
}
