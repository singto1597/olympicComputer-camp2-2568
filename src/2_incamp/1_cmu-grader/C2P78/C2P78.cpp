#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int destination;
    int weight;
};

const int INFINITY_VALUE = 1e9;

int main(){
    int c;
    cin >> c;

    for (int _ = 0; _ < c; _++){

        
        int node_number;    
        int edge_number;
        cin >> node_number >> edge_number;
        vector<Edge> adj_list[node_number];

        for (int i = 0; i < edge_number; i ++){
            int start_node;
            int to_node;
            int weight;
            cin >> start_node >> to_node >> weight;

            adj_list[start_node].push_back({to_node, weight});


        }

        vector<int> distance(node_number, INFINITY_VALUE);

        for (int step = 0; step < node_number - 1; step++){
            for (int u = 0; u < node_number; u++){
                for (Edge current_edge : adj_list[u]){
                    distance[current_edge.destination] = min(distance[current_edge.destination], distance[u] + current_edge.weight);
                }
            }
        }
        bool hasNegativeCycle = false;
        for (int u = 0; u < node_number; u++){
            for (Edge current_edge : adj_list[u]){
                if (distance[current_edge.destination] > distance[u] + current_edge.weight) {
                    hasNegativeCycle = true;
                }
            }
        }

        if(hasNegativeCycle){
            cout << "possible" << endl;
        }
        else{
            cout << "not possible" << endl;
        }
        
    }
}