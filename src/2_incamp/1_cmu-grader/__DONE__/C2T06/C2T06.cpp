#include <bits/stdc++.h>

using namespace std;

long long dp[1000005] = {};
const long long MOD = 1000000007;
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
    vector<long long> prefix_sum(n + 5, 0);
    array[0] = 1;
    array[1] = 1;

    prefix_sum[0] = 1;
    prefix_sum[1] = 2;

    for (long long i = 2; i <= n; i++){
        if (i - k - 1 < 0){
            array[i] = prefix_sum[i-1];

        }
        else{
            array[i] = (prefix_sum[i-1] - prefix_sum[i - k - 1] + MOD) % MOD;
        }
        prefix_sum[i] = (array[i] + prefix_sum[i-1]) % MOD;
        
        
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