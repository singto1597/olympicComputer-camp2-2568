#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

vector<int> dp;

int recur(int i){
    if (i == 0 ){
        dp[i] = arr[i];
        return arr[i];
    }
    if (i == 1) {
        return max(arr[0], arr[1]);
    }
    if (dp[i] != 0){
        return dp[i];
    }
    dp[i] = max(arr[i] + recur(i - 2), recur(i - 1));
    // cout << a << endl; 
    return dp[i];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;

    arr.assign(n, 0);
    dp.assign(n, 0);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << recur(n - 1) << endl;
}