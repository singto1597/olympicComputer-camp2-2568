#include <bits/stdc++.h>

using namespace std;

vector<int> adj_list[100000+5];
vector<int> adj_list_out[100000+5];
bool visited[100000+5];

void bfs(int start_node, int target_node){
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    bool found = false;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        // cout << u << " ";


        if(u == target_node){
            cout << "Yes" << endl;
            found = true;
            break;
        }

        for(int v : adj_list[u]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }

    if (!found){
        cout << "No" << endl;
    }
    
}

int main(){
    int n,m;
    cin >> n >> m;
    
    
    
    for (int i = 0; i < m; i++){
        int node, line;
        cin >> node >> line;
        adj_list[node].push_back(line);
        adj_list_out[line].push_back(node);
        // adj_list[line].push_back(node);
    }
    for (int i = 1; i <= n; i++){
        sort(adj_list[i].begin(), adj_list[i].end());
        cout << i;
        for (int v : adj_list[i]){
            cout << "->" << v ;
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++){
        cout << adj_list_out[i].size() << " " << adj_list[i].size();
        
        cout << endl;
    }

    // int start_node, target_node;
    // cin >> start_node >> target_node;
    
    // bfs(start_node, target_node);
    
    
}