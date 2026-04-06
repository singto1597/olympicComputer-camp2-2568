#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> dp ;

long long binomialCoeff(long long n, long long k){
    if (k > n) return 0;

    if (k == 0 || k == n) return 1;

    if (dp[n][k] != 0) return dp[n][k];
    
    dp[n][k] = binomialCoeff(n-1, k-1) + binomialCoeff(n - 1, k);
    return dp[n][k] ;
}

int main(){
    long long n, k;
    cin >> n >> k;

    dp.assign(n + 1, vector<long long>(k + 1, 0));

    cout << binomialCoeff(n,k);
}