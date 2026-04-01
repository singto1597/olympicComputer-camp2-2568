#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, order;
    cin >> n >> order;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++){
        int number;
        cin >> number;
        
        pq.push(number); 

        if (pq.size() > order) {
            pq.pop();
        }

        cout << pq.top() << "\n";
    }
    
    return 0;
}