#include <bits/stdc++.h>

long long dp[60] = {};



long long recur(long long n){
    if (n == 0 || n == 1){
        dp[n] = 1;
        return 1;
    }
    if (n < 0){
        dp[n] = 0;
        return 0;
    }

    if (dp[n] != 0){
        return dp[n];
    }

    dp[n] = recur(n - 1) + recur(n - 3) + recur(n - 5);

    return dp[n];
}

long long bottom_up(long long n){
    long long array[n+5] = {};
    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    array[3] = 2;
    array[4] = 3;
    array[5] = 4;
    for (int i = 5; i <= n; i++){
        array[i] = array[i-1] + array[i-3] + array[i-5];
    }
    return array[n];
}

using namespace std;

int main(){
    int n;
    cin >> n;
    // cout << recur(n) << endl;
    cout << bottom_up(n) << endl;

    // for (int i = 0; i<= n; i++){
    //     cout << dp[i] << " ";
    // }
}