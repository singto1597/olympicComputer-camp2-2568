#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;

long long botton_up(long long n){
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i<= n; i++){
        dp[i] = (i-1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

long long recur(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    dp[1] = 0;
    dp[2] = 1;
    if (dp[n] != 0){
        return dp[n];
    }
    dp[n] = (n-1) * (recur(n - 1) + recur(n - 2));
    //      อยู่ได้    สลับได้ตัว 1       สลับได้ตัว 2
    return dp[n];
}

int main(){
    int n;
    cin >> n;

    dp.assign(n + 1, 0);

    // cout << recur(n) << endl;
    cout << botton_up(n) << endl;

}