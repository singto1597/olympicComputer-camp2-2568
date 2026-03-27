#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;

bool arr[N] = {};

void sieve(){
    arr[0] - false;
    arr[1] - false;

    for(int i = 2; i < N; i++){
        arr[i] = true;
    }

    for(int i = 2; i <= sqrt(N); i++){
        if(arr[i]){
            for(int j = 2; j <= N/i; j++){
                arr[i*j] = false;
            }
        }
    }
}

int main(){
    sieve();
    int number;
    cin >> number;

    
    while(number){
        
        bool found = false;
        
        for(int a = 2; a <= number/2; a++){
            int b = number - a;

            if(arr[a] && arr[b]){
                cout << number << " = " << a << " + " << b << endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout << "Goldbach's conjecture is wrong. " << endl;
        }
        
        cin >> number;
    }   

    return 0; 


}