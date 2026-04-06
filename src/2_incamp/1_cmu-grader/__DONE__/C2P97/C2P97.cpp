#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(){
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n, m, start_node, to_node;
        cin >> n >> m >> start_node >> to_node;

        vector<vector<pair<int, int>>> adj_list(n);
        

        for (int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;

            adj_list[u].push_back({v, w});
            adj_list[v].push_back({u, w});

        }

        vector<int> distance(n, INF);
        distance[start_node] = 0;

        priority_queue<pair<int, int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(pair<int,int>(0, start_node));

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();

            int d = front.first, u = front.second;
            if (d > distance[u]) continue;

            for (int j = 0; j < (int)adj_list[u].size(); j++){
                auto v = adj_list[u][j];

                if (distance[u] + v.second < distance[v.first]){
                    distance[v.first] = distance[u] + v.second;
                    pq.push(pair<int,int> (distance[v.first], v.first));
                }
            }
        }

        if (distance[to_node] == INF) {
            cout << "unreachable\n";
        } else {
            cout << distance[to_node] << "\n";
        }


    }
}