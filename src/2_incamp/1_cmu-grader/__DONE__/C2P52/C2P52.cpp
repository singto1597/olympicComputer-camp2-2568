#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> dp;

long long ur(int U, int N, long long mod){
    if (N == 0) return 1;
    if (U == 0) return 0;
    if (U == 1 && N == 1) return 1;
    if (U == 1) return 0;

    if (dp[U][N] != -1){
        return dp[U][N];
    }
    dp[U][N] = (ur(U-1, N , mod) + ur(U - 2, N - 1, mod)) % mod;

    return dp[U][N];
}



int main(){
    long long ans, mod;
    int U, N;
    mod = 1000000007;
    
    
    cin >> U >> N;
    dp.assign(U + 5, vector<long long>(N + 5, -1));
    
    cout << ur(U, N, mod) << endl;
}