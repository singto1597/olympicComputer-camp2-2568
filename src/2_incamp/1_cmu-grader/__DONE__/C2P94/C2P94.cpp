#include <bits/stdc++.h>




using namespace std;

int main(){
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        pair<int, int> times[n];

        for (int i = 0; i < n; i++){
            cin >> times[i].second >> times[i].first;
        }

        sort(times, times + n);

        int ans = 0;
        int lastTime = -1;
        
        for (int i = 0; i < n; i++){
            // cout << "k" << endl;
            // cout << times[i].first << " " << times[i+1].second << endl;
            if (times[i].second >= lastTime){
                ans++;
                lastTime = times[i].first;
            }
        }
        cout << ans << endl;

    }


}