#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

vector<int> increasing_subsequence;

//LCS

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 0){
        cout << 0 << endl;
        return 0;
    }
    arr.assign(n+5, 0);
    increasing_subsequence.assign(n + 5, 1);

    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    int max_num = 1;

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i]){
                increasing_subsequence[i] = max(increasing_subsequence[j] + 1, increasing_subsequence[i]);
                if (increasing_subsequence[i] > max_num) max_num = increasing_subsequence[i];
            }
        }
    }

    cout << max_num << endl;

}