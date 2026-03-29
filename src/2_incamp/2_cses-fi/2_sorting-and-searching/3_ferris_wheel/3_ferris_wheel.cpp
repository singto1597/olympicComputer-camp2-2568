#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    

    int n, max_weight;
    cin >> n >> max_weight;

    long long childs[n];

    for (int i = 0; i < n; i++){

        cin >> childs[i];
        
    }

    sort(childs, childs + n);

    long long ans = 0;

    long long i = 0;
    long long j = n-1;
    
    while (i <= j){
        if (childs[i] + childs[j] <= max_weight){
            ans++;
            i++;
            j--;
        }
        else{
            ans++;
            j--;
        }
    }
    cout << ans << endl;

    
}