#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100000+5]; 
bool visited[100000+5];

int main(){
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int start_node;
    cin >> start_node;
    
    if (start_node == -1) {
        cout << "0 0 0 NO\n";
        return 0;
    }

    int u = start_node;
    visited[u] = true;
    
    int path_length = 0;
    bool has_cycle = false;
    int v;

    while(cin >> v && v != -1){
        bool found_edge = false;

        for (int neighbor : adj_list[u]) {
            if (neighbor == v) {
                found_edge = true;
                break;
            }
        }

        if (!found_edge) {
            break;
        }
        path_length++;


        if (visited[v]) {
            has_cycle = true;
        }

        visited[v] = true;
        u = v;
    }

    cout << start_node << " " << u << " " << path_length << " ";
    if (has_cycle) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}