#include <bits/stdc++.h>

using namespace std;



int main(){

    long long n, ans;
    cin >> n;


    long long arr[n + 5] = {};

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (i == 0){
            ans = max(arr[i], 0LL);
        }
        else{
            long long max_end_at_i = max(arr[i], arr[i - 1] + arr[i]);
            ans = max(max_end_at_i, ans);
            arr[i] = max_end_at_i; // ไม่ใช่ input แล้ว
        }
    }
    cout << ans << endl;
}