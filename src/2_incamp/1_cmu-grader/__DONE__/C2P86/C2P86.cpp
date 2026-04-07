#include <bits/stdc++.h>

using namespace std;

// long long f(int n){
//     if (n == 0) return 1;
//     if (n == 1) return 0;

//     return f(n - 2) + g(n - 1) * 2;
// }

// long long g(int n){
//     if (n == 0) return 0;
//     if (n == 1) return 1;

//     return f(n - 1) + g(n - 2);
// }

int main(){
    int f[32] = {}, g[32] = {};
    f[0] = g[1] = 1;
    f[1] = g[0] = 0;
    for (int n = 2; n <= 30; ++n) {
        f[n] = 2 * g[n - 1] + f[n - 2];
        g[n] = f[n - 1] + g[n - 2];
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}