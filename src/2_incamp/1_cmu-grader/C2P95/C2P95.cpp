#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        vector<pair<int, int>> graph;

        for (int i = 0; i < n ;i++){
            int start, end;
            cin >> start >> end;
            graph.push_back({start,1});
            graph.push_back({end,-1});
        }
        sort (graph.begin(), graph.end());
        int ans = 0;
        int people = 0;
        for (auto temp : graph){
            people += temp.second;
            if (people > ans) ans = people;
        }

        cout << ans << endl;
    }
    return 0;
}