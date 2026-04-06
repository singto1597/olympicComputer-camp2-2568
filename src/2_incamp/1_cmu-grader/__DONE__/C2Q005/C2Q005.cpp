#include <bits/stdc++.h>

using namespace std;


/*
    a00 a01
    a10 a11

*/


struct matrix{
    long long a00, a01, a10, a11;
};


matrix multiply(matrix A, matrix B, long long mod){
    matrix ans;
    ans.a00 = (A.a00 * B.a00 + A.a01 * B.a10) % mod;
    ans.a01 = (A.a00 * B.a01 + A.a01 * B.a11) % mod;
    ans.a10 = (A.a10 * B.a00 + A.a11 * B.a10) % mod;
    ans.a11 = (A.a10 * B.a01 + A.a11 * B.a11) % mod;
    return ans;
}


matrix power(matrix base, long long p, long long mod){
    if (p == 0){
        matrix ans {1, 0, 0, 1};
        return ans;
    } 
    else if (p % 2 == 0){
        matrix half = power (base, p/2, mod);
        return multiply(half, half, mod);
    }
    else{
        return multiply(base, power(base, p-1, mod), mod);
    }
}

// long long fastExp(long long base, int p){
//     if (p == 0) return 1;
//     if (p % 2 == 0){
//         long long half = fastExp(base, p/2);
//         return half * half;
//     }
//     else{
//         return base * fastExp(base, p-1);
//     }
// }

    

int main(){
    long long n;
    int m;
    while(cin >> n >> m){
        // long long MOD = fastExp(2, m);
        long long mod = 1LL << m;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        matrix base {1,1,1,0};
        matrix ans = power(base, n-1, mod);

        cout << (ans.a00 % mod) << endl;

    }
    
    
    

        

    return 0; 


}