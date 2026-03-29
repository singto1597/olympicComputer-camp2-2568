#include <bits/stdc++.h>

using namespace std;

int main(){
    int p, q;
    cin >> p >> q;

    int pancakes[5001] = {};
    int orders[5001] = {};

    for (int i = 0; i < p; i ++){
        cin >> pancakes[i];
    }

    for (int i = 0; i < q; i ++){
        cin >> orders[i];
        reverse(pancakes + orders[i], pancakes + p);
    }

    for (int i = 0; i < p; i ++){
        cout << pancakes[i] << " ";
    }

}