#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int dp[n+5] = {};
    int salers[n+5] = {};


    for (int i = 1 ; i <= n ; i++){
        cin >> salers[i];
        if(i == 0){
            dp[i] = salers[i];
        }
        else{
            dp[i] = salers[i] + dp[i-1];
            
        }
    }
    // for (int i = 0 ; i < n ; i++){
    //     cout << dp[i] << " ";
    // }

    for (int i = 1; i <= m ; i++){
        int start, end;
        cin >> start >> end;

        int ans;
        ans = dp[end+1] - dp[start];
        cout << ans << endl;
    }


}