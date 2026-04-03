#include <bits/stdc++.h>

using namespace std;

int a[1005];
int l[1005];
int r[1005];

pair<int, int> findmax(int node){
    pair<int, int> result = make_pair(-2e9, -2e9);
    if (l[node] != 0){
        result = max(result, findmax(l[node]));
    }
    if (r[node] != 0){
        result = max(result, findmax(r[node]));
    }
    ++result.second;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }

    pair<int, int>  ans = make_pair(-2e9, -2e9);

    for (int i = 1; i<= n; i++){
        ans = max(ans, findmax(i));
        if (l[i] != 0 && r[i] != 0){
            pair<int, int> left = findmax(l[i]);
            pair<int, int> right = findmax(r[i]);
            pair<int, int> cur = make_pair(left.first + right.first +a[i], left.second + right.second +1);
            ans = max(ans, cur);
        }
    }

    cout << ans << endl;
}