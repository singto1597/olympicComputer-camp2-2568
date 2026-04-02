#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj_list[n+1];

    for (int i = 0; i < m; i++){
        int node, line;
        cin >> node >> line;
        adj_list[node].push_back(line);
        adj_list[line].push_back(node);
    }
    for (int i = 1; i <= n; i++){
        cout << i << " | ";
        sort(adj_list[i].begin(), adj_list[i].end());

        for(auto temp : adj_list[i]){
            cout << temp << " ";
        }
        cout << endl;
    }
}