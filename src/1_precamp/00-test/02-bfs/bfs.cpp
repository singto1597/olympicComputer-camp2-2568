#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int from[MAXN];
bool visited[MAXN];



void bfs_queue(int start_node){
    queue <int> q;
    q.push(start_node);
    visited[start_node] = true;
    from[start_node] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]){
            if (!visited[v]) {
                visited[v] = true;
                from[v] = u;
                q.push(v); 
            }
        }
    }
}

void bfs_queue_distant(int start_node){
    vector<int> dist(MAXN, -1);
    queue <int> q;
    q.push(start_node);
    from[start_node] = -1;
    dist[start_node] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]){
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                from[v] = u;
                q.push(v); 
            }
        }
    }
}


void bfs_queue_distant_target(int start_node, int target){
    vector<int> dist(MAXN, -1);
    queue <int> q;
    q.push(start_node);
    from[start_node] = -1;
    dist[start_node] = 0;

    if (start_node == target) {
        cout << 0 << "\n";
        return;
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]){
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                from[v] = u;

                if (v == target) {
                    cout << dist[target] << "\n";
                    return; 
                }

                q.push(v); 
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    return 0;
}