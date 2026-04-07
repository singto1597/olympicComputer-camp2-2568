#include <bits/stdc++.h>

using namespace std;

int dp[80] = {};

int f(int n){
    if (n == 0 || n == 1) return 1;
    if (dp[n] != 0){
        return dp[n];
    }
    return dp[n] = f(n - 1) + f(n - 2) * 2;
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++){
        int a;
        cin >> a;
        cout << f(a) << endl;
    }
}