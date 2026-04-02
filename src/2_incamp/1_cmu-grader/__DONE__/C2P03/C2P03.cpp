#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    int col[n] = {};

    for (int i = 0; i < n; i++){
        cin >> col[i]; 
    }

    for(int _ = 0; _ < t; _++){
        int choise;
        cin >> choise;
        int i, j;
        switch(choise){
            case 1:
                cin >> i >> j;
                i--;
                if (j > col[i]){
                    col[i]++;
                }
                break;

            case 2:
                cin >> i >> j;
                i--;
                if (j <= col[i]){
                    col[i]--;
                }
                break;

            case 3:{
                cin >> i >> j;
                i--;
                int di[9] = {-1,  0,  1, -1,  0,  1, -1,  0,  1};
                int dj[9] = { 1,  1,  1,  0,  0,  0, -1, -1, -1};

                for (int round = 0; round < 9; round++){
                    int ni = i + di[round];
                    int nj = j + dj[round];
                    if (nj <= col[ni] && col[ni] > 0){
                        col[ni]--;
                    }
                }
                break;
            }
            case 4:
                cin >> j;
                j;
                for(int coli = 0; coli < n; coli++){
                    if (j <= col[coli]){
                        col[coli]--;
                        
                    }
                }
                break;
        }
        for (int i = 0; i < n; i++){
            cout << col[i] << " "; 
        }
        cout << endl;
    }

    
}