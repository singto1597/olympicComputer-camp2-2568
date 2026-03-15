#include <bits/stdc++.h>

using namespace std;

// ข้อนี้ใช้สูตร dynamic programming
// ต้องหาจำนวนที่เป็นไปได้ในทุกราคา
// dp[j] = dp[j] + dp[j - V]
// V คือราคาของ
// ถ้าวนจาก 0 -> 50000 คือสามารถใช้ของได้ไม่จำกัด
// ถ้าวนจาก 50000 -> 0 คือ สามารถใช้ของได้แค่รอบเดียว

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int dp[50005] = {};
    int price[505] = {};
    dp[0] = 1;
    for (int i = 0; i < n; i ++){
        int pricei;
        cin >> pricei;
        price[i] = pricei;
    }
    for (int i = 0; i < n; i ++){
        for (int j = m; j >= price[i]; j--){
            dp[j] += dp[j - price[i]];
            dp[j] %= 1000007;
        }
    }
    cout << dp[m];
}