#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    int n, m;
    cin >> n >> m;

    vector<int> array(n);
    for (int i = 0; i < n; i ++){
        cin >> array[i];
    }
    sort(array.begin(), array.end());

    vector<int> gap(n-1);

    for (int i = 0; i < n - 1; i++){
        gap[i] = array[i] - array[i+1];
    }

    sort(gap.begin(), gap.end());

    int ans = array[n - 1] - array[0];

    for (int i = 0 ; i < m - 1; i ++){
        ans += gap[i];
    }

    cout << ans << endl;
}