#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long prefix_sum[n+5] = {};

    for (int i = 1; i <= n; i++){
        int number;
        cin >> number;

        prefix_sum[i] = prefix_sum[i - 1] + number;
    }

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++){
        int start, end;
        cin >> start >> end;

        cout << prefix_sum[end + 1] - prefix_sum[start] << endl;
    }
}