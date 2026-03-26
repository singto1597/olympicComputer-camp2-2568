#include <bits/stdc++.h>

using namespace std;

long long dp[1000000] = {};

long long febo(long long n){
    if (n == 1 || n == 0){
        return 1;
    }
    if (dp[n] != 0){
        return dp[n];
    }
    dp[n] = febo(n-1) + febo(n-2);
    return dp[n];
}


// long long febo(long long n){
//     if (n == 1 || n == 0){
//         return 1;
//     }

//     return febo(n-1) + febo(n-2);
// }


int main(){


    cout << febo(45) << endl;



    return 0;
}