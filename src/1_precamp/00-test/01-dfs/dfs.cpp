#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int from[MAXN];
bool visited[MAXN];

void dfs_recur(int u){
    visited[u] = true;

    for (int v : adj[u]){
        if (!visited[v]){
            from[v] = u;
            dfs_recur(v);
        }
    }
}

void dfs_stack(int start_node){
    stack <int> s;
    s.push(start_node);
    visited[start_node] = true;
    from[start_node] = -1;

    while(!s.empty()){
        int u = s.top();
        s.pop();
        
        for (int v : adj[u]){
            if (!visited[v]) {
                visited[v] = true;
                from[v] = u;
                s.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    dfs_recur(1);
    return 0;
}