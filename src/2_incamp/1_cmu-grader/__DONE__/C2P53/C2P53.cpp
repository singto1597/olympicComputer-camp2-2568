#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long arr[n] = {};
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }


    for (int i = 0; i < n; i++){
        if (i == 0){
            if (arr[i] > arr[i+1]){ 
                cout << i << "\n"; 
                break;
            }
            

        }
        else if (i == n - 1){
            if (arr[n - 1] > arr[n - 2]){ 
                cout << i << "\n"; 
                break;
            }
        }
        else{
            if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i]){ 
                cout << i << "\n"; 
                break;
            }
        }
    }

}