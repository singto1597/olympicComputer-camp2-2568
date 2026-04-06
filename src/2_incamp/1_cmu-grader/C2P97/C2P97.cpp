#include <bits/stdc++.h>

using namespace std;



int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n, m, start_node, to_node;

        vector<vector<pair<int, int>>> adj_list;
        

        for (int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;

            adj_list[u].push_back({v, w});
            adj_list[v].push_back({u, w});

        }


    }
}