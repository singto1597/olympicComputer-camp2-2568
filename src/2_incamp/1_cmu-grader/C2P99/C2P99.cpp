#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int scs(string x, string y, int i, int j){
    if (j == 0) return i;
    if (i == 0) return j;

    if (dp[i][j] != 0){
        return dp[i][j];
    }

    if (x[i - 1] == y[j - 1]) return dp[i][j] = 1 + scs(x, y, i - 1, j - 1);
    return dp[i][j] = 1 + min(scs(x, y, i - 1, j), scs(x, y, i, j - 1));
} 

int scs_bottom_up(string x, string y){
    int m = x.size(), n = y.size();

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (x[i - 1] == y[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];

    
}

int main(){
    string x, y;
    cin >> x >> y;

    dp.assign(x.size() + 1, vector<int>(y.size() + 1, 0));

    // cout << scs(x, y, x.size(), y.size()) << endl;
    cout << scs_bottom_up(x, y) << endl;
}