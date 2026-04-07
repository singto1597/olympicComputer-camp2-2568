#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(1005, vector<int>(1005, 0));

int lps(string s, int i, int j){
    if (i == j) return 1;
    if (i > j)  return 0;

    if (dp[i][j] != 0){
        return dp[i][j];
    }

    if (s[i] == s[j]) return dp[i][j] = 2 + lps(s, i + 1, j - 1);

    return dp[i][j] = max(lps(s, i + 1, j), lps(s, i, j - 1));
    
}

int lps_bottom_up(string s){
    int n = s.length();
    for (int i = 0; i < n; i++) dp[i][i] = 1;   
    for (int len = 2; len <= n; len++){
        for (int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            if(s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        // cout << lps(s, 0, s.size() - 1) << "\n";
        cout << lps_bottom_up(s) << "\n";
    }
    return 0;
}