#include <bits/stdc++.h>

using namespace std;

vector<int> adj_list[100000+5];
bool visited[100000+5];

void dfs_recur(int u){
    visited[u] = true;
    cout << u << " ";
    for(int v : adj_list[u]){
        if (!visited[v]){
            dfs_recur(v);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    
    
    
    for (int i = 0; i < m; i++){
        int node, line;
        cin >> node >> line;
        adj_list[node].push_back(line);
        adj_list[line].push_back(node);
    }
    for (int i = 1; i <= n; i++){
        sort(adj_list[i].begin(), adj_list[i].end());
        
    }
    
    int u;
    cin >> u;
    dfs_recur(u);
}