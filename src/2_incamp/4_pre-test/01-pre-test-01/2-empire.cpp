#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i ++){
            cin >> arr[i];
        
        }
        sort(arr, arr + n);
        // int ans = 0;
        // bool getOut[n] = {};
        int temp = 0;
        int first = -1;
        int last = -1;
        bool visited = false;
        for (int i = n - 1; i >= 0; i --){
            for (int j = 0; j <= i; j++){

                    temp = arr[j] + arr[i];
                    if (temp % k == 0){
                        visited = true;
                        first = j;
                        last = i;
                        break;
                    }


                
            }
            if (visited){
                break;
            }
        }

        // cout << first << " " << last << endl;
        if (first == -1 && last == -1) cout << n << "\n";
        else cout << (n - 1) - (last - first) << "\n";
        cout << arr[first] << " " << arr[last] << endl;
        // cout << " dfsfsd " << endl;

        
    }

}