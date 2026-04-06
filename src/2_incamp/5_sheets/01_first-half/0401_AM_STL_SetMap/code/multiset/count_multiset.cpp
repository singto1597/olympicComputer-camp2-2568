// multiset::count
#include <iostream>
#include <set>

using namespace std;

int main ()
{
  int myints[]={10,73,12,22,73,73,12};
  int no;
  multiset<int> mymultiset (myints,myints+7);
  
  cout << "input num: ";
  cin >> no;

  if(mymultiset.count(no)){
       cout << no << " appears " << mymultiset.count(no) << " times in mymultiset.\n";
  }else{
      cout << no << " is not an element of mymultiset.\n";
  }
  
 
  return 0;
}