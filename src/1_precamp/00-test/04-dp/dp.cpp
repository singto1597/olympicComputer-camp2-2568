#include <bits/stdc++.h>

using namespace std;

long long dp[1000000] = {};

long long febo(long long n){
    if (n == 1 || n == 0){
        return 1;
    }
    if (dp[n] != 0){
        return dp[n];
    }
    dp[n] = febo(n-1) + febo(n-2);
    return dp[n];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << febo(50) << endl;
    return 0;
}