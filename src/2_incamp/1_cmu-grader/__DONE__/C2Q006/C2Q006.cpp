#include <bits/stdc++.h>

using namespace std;

vector<int> adj_list[20];
bool visited[20] = {};

int main(){
    int students, edges;
    cin >> students >> edges;
    for (int i = 0; i < edges; i ++){
        int from, to;
        cin >> from >> to;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    int start;
    cin >> start;

    stack<int> s;
    s.push(start);
    // visited[start]= true;

    while(!s.empty()){
        int u = s.top();
        s.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        cout << u <<  " " ;
        for (int i = adj_list[u].size() - 1; i >= 0; i--){
            int v = adj_list[u][i];
            if (!visited[v]){
                s.push(v);
            }
        }

    }
    
}