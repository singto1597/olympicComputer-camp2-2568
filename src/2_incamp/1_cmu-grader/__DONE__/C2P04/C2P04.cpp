#include <bits/stdc++.h>

using namespace std;


int di[8] = {-1, -1, -1,  0,  0,  1,  1,  1};
int dj[8] = {-1,  0,  1, -1,  1, -1,  0,  1};

int main(){
    int table[25][25] = {0};
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> table[i][j];
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(table[i][j]){
                count++;
                queue<pair<int,int>> q;
                q.push({i,j});
                table[i][j] = 0;

                while(!q.empty()){
                    auto u = q.front();
                    q.pop();

                    int curr_i = u.first;
                    int curr_j = u.second;

                    for(int path_i = 0; path_i < 8; path_i++){
                        int ni = curr_i + di[path_i];
                        int nj = curr_j + dj[path_i];

                        if (table[ni][nj]){
                            q.push({ni,nj});
                            table[ni][nj] = 0;
                        }
                    }

                }
            }
        }
    }

    cout << count << endl;
}