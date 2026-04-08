#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;

    int prices[n + 1] = {};

    int left_profit[n + 1] = {};
    int right_profit[n + 1] = {};
    
    for (int i = 0; i < n; i ++){
        cin >> prices[i];
    }
    int min_price = prices[0];

    for (int i = 1; i < n; i++){
        min_price = min(min_price, prices[i]);
        int profit_if_sell_today = prices[i] - min_price;

        left_profit[i] = max(left_profit[i - 1], profit_if_sell_today);
    }

    int max_price = prices[n-1];

    for (int i = n - 2; i >= 0; i--){
        max_price = max(max_price, prices[i]);
        int profit_if_buy_today = max_price - prices[i];

        right_profit[i] = max(right_profit[i + 1], profit_if_buy_today);
    }

    int max_total_profit = 0;

    for (int i = 0; i < n; i++){
        int total_profit = left_profit[i] + right_profit[i];

        max_total_profit = max(total_profit, max_total_profit);
    }

    cout << max_total_profit << endl;

}