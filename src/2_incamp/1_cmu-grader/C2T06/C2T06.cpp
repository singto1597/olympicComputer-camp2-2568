#include <bits/stdc++.h>

using namespace std;

long long dp[1000005] = {};

long long k = 0;

long long recur(long long n){
    if (n == 1 || n == 0) return 1;
    
    if (dp[n] != 0) return dp[n];

    long long ans = 0;

    for (long long i = 1; i <= k; i++){
        if (n - i >= 0){
            ans = (ans + recur(n - i)) % 1000000007;

        }
    }

    dp[n] = ans;

    return dp[n];
}


int main(){
    long long n;
    cin >> n >> k;

    cout << recur(n) << endl;
}