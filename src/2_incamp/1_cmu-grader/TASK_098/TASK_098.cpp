#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;


    vector<vector<int>> dp(n, vector<int>(m, 0));
    int max_size = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            
            if (val == 1) {

                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                max_size = max(max_size, dp[i][j]);
            } else {
                dp[i][j] = 0; 
            }
        }
    }

    cout << max_size << "\n";

    return 0;
}