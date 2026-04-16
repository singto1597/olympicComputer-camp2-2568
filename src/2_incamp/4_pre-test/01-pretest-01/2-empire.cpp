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

        int temp = 0;

        vector<pair<int, int>> ans_all;

        bool visited = false;
        for (int i = n - 1; i >= 0; i --){
            for (int j = 0; j <= i; j++){

                    temp = arr[j] + arr[i];
                    if (temp % k == 0){
                        ans_all.push_back({j, i});
                    }


                
            }

        }

        int max_index = 0;
        int max_diff = -1;

        int i = 0;

        if (ans_all.empty()){
            cout << n << endl;
            continue;
        }

        for (auto ans : ans_all){
            if (ans.second - ans.first > max_diff){
                max_diff = ans.second - ans.first ;
                max_index = i;
            }
            i++;
        }

        // cout << first << " " << last << endl;
        // if (first == -1 && last == -1) cout << n << "\n";
        

        int first = ans_all[max_index].first;
        int last  = ans_all[max_index].second;
        cout << (n - 1) - (last - first) << "\n";
        // cout << arr[first] << " " << arr[last] << endl;
        // cout << " dfsfsd " << endl;

        
    }

}