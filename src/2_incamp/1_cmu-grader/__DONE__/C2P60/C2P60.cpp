#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int recur(string x, string y, int i, int j){
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (x[i - 1] == y[j - 1]){
        return dp[i][j] = 1 + recur(x, y, i-1, j-1);
    }
    return dp[i][j] = max(recur(x, y, i - 1, j), recur(x, y, i, j - 1));
}

int bottom_up(string x, string y){
    int m = x.length(), n = y.length();
    for (int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (x[i - 1] == y[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string x, y;
    cin >> x;
    cin >> y;

    // dp.assign(1005, vector<int>(1005, -1));
    dp.assign(1005, vector<int>(1005, 0));


    // cout << recur(x, y, x.size(), y.size());
    cout << bottom_up(x, y);
}