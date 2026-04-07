#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int edit_distance(string x, string y, int i, int j){
    if (i == 0) return j;
    if (j == 0) return i;
    if (dp[i][j] != -1) return dp[i][j];
    if (x[i - 1] == y[j - 1]){
        return dp[i][j]=edit_distance(x, y, i - 1, j - 1);
    }
    return dp[i][j] = 1 + min({
        edit_distance(x, y, i - 1, j),      //delete
        edit_distance(x, y, i, j - 1),      //insert
        edit_distance(x, y, i - 1, j - 1)   //replace
    });
}

int main(){
    string x, y;
    cin >> x >> y;
    dp.assign(1005, vector<int>(1005, -1));

    cout << edit_distance(x, y, x.size(), y.size());

}