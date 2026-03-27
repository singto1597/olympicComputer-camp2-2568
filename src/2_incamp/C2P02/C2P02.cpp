#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie();
    int n;
    cin >> n;
    int row[55];
    int sum = 0;
    int avg = 0;
    for (int i = 0; i < n; i++){
        cin >> row[i];
        sum += row[i];
    }
    avg = sum/n;

    int answ = 0;

    for (int i = 0; i < n; i++){
        if (row[i] > avg){
            answ += row[i] - avg;
        }
    }
    cout << answ << endl;
}