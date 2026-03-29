#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    int n; 
    cin >> n;

    
    for (int i = 1; i <= n; i++){
        string ans = "";
        int temp = i;
        while(temp > 0){
            ans = to_string(temp % 2) + ans;
            temp /= 2;
        }
        cout << ans << " ";
    }
}