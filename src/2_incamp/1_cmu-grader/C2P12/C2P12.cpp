#include <bits/stdc++.h>

using namespace std;

int main(){
    int m,n,c; cin >> m >> n >> c;

    set<int>a;
    set<int>b;
    vector<int> result;

    for (int i = 0; i < m; i++){
        int k;
        cin >> k;
        a.insert(k);
    }
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        b.insert(k);
    }
    
    switch(c){
        case 0:
            set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
            break;

        case 1:
            set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
            break;

        case 2:
            set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
            break;

    }
    for(int i : result){
        cout << i << " ";
    }
}