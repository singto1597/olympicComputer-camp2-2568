#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int max = 0;
    int difference[1000001] = {};
    
    for (int i = 0; i < n; i++){
        int come, out;
        cin >> come >> out;
        difference[come]++;
        difference[out]--;
    }   
    int currentPeople = 0;
    for (int i = 0; i < 1000001; i++){
        currentPeople += difference[i];
        if (currentPeople > max){
            max = currentPeople;
        }
    }
    cout << max << "\n";
}