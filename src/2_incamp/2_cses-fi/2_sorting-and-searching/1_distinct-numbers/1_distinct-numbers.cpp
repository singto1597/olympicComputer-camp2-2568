#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    set<long long> numbers;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int number;
        cin >> number;
        numbers.insert(number);
    }
    cout << numbers.size();
}