#include <bits/stdc++.h>

using namespace std;

void print_order(priority_queue<int> list, int order){
    int number;
    int i = 0;
    while(!list.empty() && i < order - 1){
        list.pop();
        i++;
    }
    cout << list.top() << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, order;
    cin >> n >> order;

    priority_queue<int> list;

    for (int i = 0; i < n; i++){
        int number;
        cin >> number;
        list.push(number);

        print_order(list, order);
    }
}