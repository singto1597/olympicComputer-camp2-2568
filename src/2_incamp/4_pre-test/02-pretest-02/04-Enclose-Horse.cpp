#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int min = 1e9;
    for (int j = 0; j < m; j++){
        string number;
        cin >> number;
        if (number == "X"){
            cout << 0 << endl;
            return 0;
        }
        
        int number_number = stoi(number);
        if (number_number < min) min = number_number;
    }
    cout << min << endl;
    return 0;
}