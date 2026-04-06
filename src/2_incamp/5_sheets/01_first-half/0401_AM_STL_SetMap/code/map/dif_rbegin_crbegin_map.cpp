#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
vector<int> v{100,200,300,400};  
//vector<int>::const_reverse_iterator itr=v.crbegin();  
vector<int>::reverse_iterator itr=v.rbegin();  
  *itr=500;  
cout<<*itr;  
return 0;}  