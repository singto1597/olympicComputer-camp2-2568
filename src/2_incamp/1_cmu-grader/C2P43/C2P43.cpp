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


int main(){
    int n, f0, f1;
    cin >> n >> f0 >> f1;
    cout << febo(n, f0, f1);

}