#include <bits/stdc++.h>

using namespace std;

vector<long long> arr;
vector<long long> dp;

long long recur(long long n){
    if (n < 0) return 0;
    if (dp[n] != 0) {
        return dp[n];
    }
    dp[n] = max(recur(n-2) + arr[n], recur(n - 1));
    return dp[n];
}

int main(){
    int n;
    cin >> n;

    arr.assign(n + 5 , 0);
    dp.assign(n + 5 , 0);

    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    cout << recur(n) << endl;
}   