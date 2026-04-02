#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

vector<pair<int, int>> adj_list[100000+5];
bool visited[100000+5];
// bool visited_path[10000+5][10000+5] = {};

// void bfs(int start_node, int target_node){
//     queue<int> q;
//     q.push(start_node);
//     visited[start_node] = true;
//     bool found = false;

//     while(!q.empty()){
//         int u = q.front();
//         q.pop();
//         // cout << u << " ";


//         if(u == target_node){
//             cout << "Yes" << endl;
//             found = true;
//             break;
//         }

//         for(int v : adj_list[u]){
//             if (!visited[v]){
//                 visited[v] = true;
//                 q.push(v);
//             }
//         }
//     }

//     if (!found){
//         cout << "No" << endl;
//     }
    
// }

int main(){
    int n,m;
    cin >> n >> m;
    
    
    
    for (int i = 0; i < m; i++){
        int node, line, weight;
        cin >> node >> line >> weight;
        adj_list[node].push_back({line, weight});
        adj_list[line].push_back({node, weight});
    }
    for (int i = 1; i <= n; i++){
        sort(adj_list[i].begin(), adj_list[i].end());
        // cout << i;
        // for (int v : adj_list[i]){
        //     cout << "->" << v ;
        // }
        // cout << endl;
    }


    int u;
    cin >> u;
    
    if (u == -1) {
        cout << "0 0\n";
        return 0;
    }

    // int current_node = 0, last_node = 0;
    // cin >> current_node;

    // visited[current_node] = 1;

    int path_length = 0;
    int total_weight = 0;
    int v;

    while(cin >> v && v != -1){
        bool found_edge = false;
        int edge_weight = 0;

        for (auto edge : adj_list[u]) {
            if (edge.f == v) {
                found_edge = true;
                edge_weight = edge.s;
                break;
            }
        }

        if (!found_edge) {
            break;
        }

        path_length++;
        total_weight += edge_weight;

        if (visited[v]) {
            break;
        }

        visited[v] = true; 
        u = v;


    }

    cout << path_length << " " << total_weight << endl;

    // int start_node, target_node;
    // cin >> start_node >> target_node;
    
    // bfs(start_node, target_node);
    
    
}