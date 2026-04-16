#include <bits/stdc++.h>

using namespace std;

void pair_print(int n){
    if (n <= 1){
        cout << "int";
        return;
    }
    
    cout << "pair<" ;
    pair_print(n - (n / 2));
    cout << "," ;
    
    pair_print(n / 2);


    
    cout << ">" ;
}

int main(){
    int n;
    cin >> n;
    pair_print(n);

}