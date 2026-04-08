#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n;
    int arr[n];

    for (int i = 1; i <= n;i ++) cin >> arr[i];

    cin >> k;

    int rope[k+1];
    for (int i = 0; i <= k; i++){
        if (i == 0){
            rope[i] = 0;
        }
        else{
            int max_at_j = arr[i];
            for (int j = 1; j <= i; j++){
                max_at_j = max(max_at_j, rope[i - j] + arr[j]);
            }
            rope[i] = max_at_j;
        }
    }
    cout << rope[k] << endl;
}