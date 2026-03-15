#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool table[1001][1001] = {};
    int x, y, count = 0;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (table[x][y]){
            continue;
        }
        else{
            table[x][y] = 1;
            count++;
        }
    }
    cout << count << endl;
}