#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj_list_in[n+1];
    vector<int> adj_list_out[n+1];

    for (int i = 0; i < m; i++){
        int node, line;
        cin >> node >> line;
        adj_list_in[node].push_back(line);
        adj_list_out[line].push_back(node);
        // adj_list[line].push_back(node);
    }
    for (int i = 1; i <= n; i++){
        cout << adj_list_out[i].size() << " " << adj_list_in[i].size();
        cout << endl;
    }
}