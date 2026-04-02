#include <bits/stdc++.h>

using namespace std;

vector<int> adj_list[100000+5];
bool visited[100000+5];

void bfs(int start_node){
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        // cout << u << " ";

        for(int v : adj_list[u]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
            }
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
    
    int ans = 0;

    for (int i = 1; i <= n; i++){
        if(!visited[i]){
            bfs(i);
            ans++;
        }
        
    }

    cout << ans << endl;
    
    
}