#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second 

const long long INF = 2e9;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int node_number, edge_number;
    cin >> node_number >> edge_number;

    int start_node, end_node;
    cin >> start_node >> end_node;

    vector<vector<pair<long long, long long>>> adj_list(node_number + 5);

    for (int i = 0; i < edge_number; i++){
        long long start, end, weight;
        cin >> start >> end >> weight;

        adj_list[start].push_back({end, weight});
        adj_list[end].push_back({start, weight});
    }

    vector<long double> distance(node_number + 5, INF);
    distance[start_node] = 1;
    vector<long long> from_node(node_number + 5, -1);
    from_node[start_node] = -1;
    
    priority_queue<pair<long double, long long>, vector<pair<long double, long long>>, greater<pair<long double, long long>>> pq;
    pq.push({1, start_node});

    while (!pq.empty()){
        auto front = pq.top();
        pq.pop();

        long long w = front.f;
        long long u = front.s;

        for (auto v : adj_list[u]){
            if (w > distance[u]) continue;

            long double dis_v_log = log(v.s);

            if (distance[u] + dis_v_log < distance[v.f]){
                distance[v.f] = distance[u]  + dis_v_log;
                // cout << distance[v.f] << endl;
                pq.push({distance[v.f], v.f});
                from_node[v.f] = u;
            }
        }
    }

    if (distance[end_node] == INF){
        cout << "Impossible" << endl;
    }
    else{
        if (start_node == end_node) cout << start_node << endl;
        // cout << distance[end_node] << endl; 
        long long u = end_node;
        long long v = from_node[end_node];
        cout << start_node << " ";
        stack<long long> s;
        while (v != -1){
            s.push(u);
            u = v;
            v = from_node[u];
        }
        while (!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        // cout << from_node[end_node] << endl;
    }
    return 0;
}