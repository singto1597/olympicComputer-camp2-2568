#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

struct Edge {
    int v;
    int weight;
    bool operator<(const Edge& other) const {
        if (v != other.v) {
            return v < other.v; 
        }
        return weight < other.weight; 
    }
};

vector<Edge> adj_list[100000+5];
bool visited[100000+5];

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
    }


    int u;
    cin >> u;
    
    if (u == -1) {
        cout << "0 0\n";
        return 0;
    }


    int path_length = 0;
    int total_weight = 0;
    int v;

    while(cin >> v && v != -1){
        bool found_edge = false;
        int edge_weight = 0;

        for (auto edge : adj_list[u]) {
            if (edge.v == v) {
                found_edge = true;
                edge_weight = edge.weight;
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
}