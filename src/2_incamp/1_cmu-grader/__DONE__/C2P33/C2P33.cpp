#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;

    // node | to...
    map<int, vector<int>> adj_lists;

    
    for (int i = 0; i < n; i++){
        int u, to;
        cin >> u >> to;
        
        adj_lists[u].push_back(to);
        adj_lists[to].push_back(u);
    }
    
    int start_node, ttl;
    
    while(cin >> start_node >> ttl && (start_node != 0 || ttl != 0)){
        map<int, int> distance_map;
        // map<int, int> visited_map;
        queue<int> q;
        q.push(start_node);
        distance_map[start_node] = 0;   

        // int visited = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            // visited_map[u] = true;
            int distance = distance_map[u];
            
            for(int v : adj_lists[u]){
                if (distance_map[u] + 1 <= ttl && distance_map.count(v) == 0){
                    distance_map[v] = distance_map[u] + 1;
                    q.push(v);
                    // visited++;
                    // cout << v << endl;
                }
            }
        }
        // cout <<  << endl;
        cout << adj_lists.size() - distance_map.size()<< endl;

    }

}