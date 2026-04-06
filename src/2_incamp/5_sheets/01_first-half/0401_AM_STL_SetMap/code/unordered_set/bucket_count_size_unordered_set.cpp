// unordered_set::bucket_size
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main ()
{
  unordered_set<std::string> myset =
  { "red", "green", "blue", "yellow", "purple", "pink" };

  unsigned nbuckets = myset.bucket_count();

  cout << "myset has " << nbuckets << " buckets:\n";

  for (unsigned i=0; i<nbuckets; ++i) {
    cout << "bucket #" << i << " has " << myset.bucket_size(i) << " elements.\n";
  }

  return 0;
}
