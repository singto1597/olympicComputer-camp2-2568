#include <bits/stdc++.h>

using namespace std;

long long memo[55][55];

long long dice(int sum, int n, int f){
    if (sum < 0) return 0;
    if (n == 0 && sum == 0) return 1; 
    if (n == 0 || sum == 0) return 0;

    if (memo[n][sum] != -1) return memo[n][sum];

    long long ans = 0;

    for (int i = 1; i <= f; i++){
        if (sum >= i)
            ans += dice(sum-i, n-1, f);
    }

    return memo[n][sum] = ans;

}

int main(){
    int n, f, sum;
    cin >> n >> f >> sum;

    memset(memo, -1, sizeof(memo));

    cout << dice(sum, n, f) << endl;
}