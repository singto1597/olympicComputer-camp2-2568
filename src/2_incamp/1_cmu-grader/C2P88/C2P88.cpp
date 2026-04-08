#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n ;
    
    long long dp[n + 5] = {};

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        if (i >= m){
            dp[i] += dp[i - m];

        }
    }

    cout << dp[n] << endl;
    
}