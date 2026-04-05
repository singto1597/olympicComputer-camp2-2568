#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int main(){

    int t;
    if (!(cin >> t)) return 0; // รับจำนวน Test case

    while (t--) {
        int adj_matrix[120][120] = {0};
        bool active[120] = {false};
        for (int i = 0; i < 120; i++) {
            for (int j = 0; j < 120; j++)
            adj_matrix[i][j] = INF;
            adj_matrix[i][i] = 0;
        }
 
        int start_node;
        int to_node;
        cin >> start_node >> to_node;
        while (start_node && to_node){
            adj_matrix[start_node][to_node] = 1;
            active[start_node] = true; 
            active[to_node] = true;

            cin >> start_node >> to_node;
        }
        int V = 120;
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    adj_matrix[i][j] = min(adj_matrix[i][j],adj_matrix[i][k]+adj_matrix[k][j]);

        double sum_paths = 0;
        int node_count = 0;
            
        for (int i = 0; i < V; i++) {
            if (active[i]) {
                node_count++;
            }
        }

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (active[i] && active[j] && i != j) {
                    sum_paths += adj_matrix[i][j];
                }
            }
        }
        int total_pairs = node_count * (node_count - 1);

        cout << fixed << setprecision(3) << (sum_paths / total_pairs) << "\n";
        
    }
}