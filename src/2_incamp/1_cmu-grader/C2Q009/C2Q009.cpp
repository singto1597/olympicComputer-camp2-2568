#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int ds(string s1, string s2, int i, int j){
    if (j == 0) return 1;
    if (i == 0) return 0;

    if (dp[i][j] != 0){
        return dp[i][j];
    }

    if (s1[i - 1] == s2[j - 1]) return dp[i][j] = ds(s1, s2, i - 1, j) + ds(s1, s2, i - 1, j - 1);
    return dp[i][j] = ds(s1, s2, i - 1, j);
}

int ds_bottom_up(string s1, string s2){
    int m = s1.size(), n = s2.size();
    dp.assign(m+5, vector<int>(n+5, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = 1;

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000007;
            }
            else{
                dp[i][j] = dp[i - 1][j] % 1000000007;
            }
        }
    }
    return dp[m][n] % 1000000007;
    
}

int main(){
    string x, y;
    getline(cin, x);
    getline(cin, y);

    // cout << ds(x, y, x.size(), y.size()) << endl;
    cout << ds_bottom_up(x, y) << endl;
}