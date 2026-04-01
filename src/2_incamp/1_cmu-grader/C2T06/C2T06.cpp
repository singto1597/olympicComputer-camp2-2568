#include <bits/stdc++.h>

using namespace std;

long long dp[1000005] = {};

long long k = 0;

long long recur(long long n){
    if (n == 1 || n == 0){
        dp[n] = 1;
        return 1;
    
    }
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

long long bottom_up(long long n){
    vector<long long> array(n + 5, 0);
    array[0] = 1;
    array[1] = 1;

    for (long long i = 2; i <= n; i++){
        for (long long j = 1; j <= k; j++){
            if (i - j < 0) continue;
            array[i] = (array[i] + array[i - j]) % 1000000007;
        }
    }
    //for (int i = 0; i<= n; i++){
    //    cout << array[i] << " ";
    //}
    return array[n];
}


int main(){
    long long n;
    cin >> n >> k;

    // cout << recur(n) << endl;
    cout << bottom_up(n) << endl;
    //for (int i = 0; i<= n; i++){
    //    cout << dp[i] << " ";
    //}

}