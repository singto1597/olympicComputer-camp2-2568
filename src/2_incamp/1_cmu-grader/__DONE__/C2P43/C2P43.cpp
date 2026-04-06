#include <bits/stdc++.h>

using namespace std;

long long dp[100] = {};
bool visited[100] = {false};

long long febo(int n, int f0, int f1){
    if (n == 0){
        return f0;
    }
    else if (n == 1){
        return f1;
    }
    if (visited[n]){
        return dp[n];
    }
    dp[n] = febo(n-1, f0, f1) + febo(n-2, f0, f1);
    visited[n] = true;
    return dp[n];
}

long long febo_bottom_up(int n, int f0, int f1){
    dp[0] = f0;
    dp[1] = f1;

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

long long febo_bottom_up_optimize(int n, int f0, int f1){
    if (n == 0) return f0;
    if (n == 1) return f1;
    long long dp_n_1 = f1;
    long long dp_n_2 = f0;

    long long dp_i = 0;

    for (int i = 2; i <= n; i++){
        dp_i = dp_n_1 + dp_n_2;
        dp_n_2 = dp_n_1;
        dp_n_1 = dp_i;
    }

    return dp_i;
}



int main(){
    int n, f0, f1;
    cin >> n >> f0 >> f1;
    cout << febo_bottom_up_optimize(n, f0, f1);

}