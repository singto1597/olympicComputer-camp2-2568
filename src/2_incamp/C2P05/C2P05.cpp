#include <bits/stdc++.h>

using namespace std;


int dx[8] = {-1, -2, -2, -1, 1, 2,  2,  1};
int dy[8] = {-2, -1,  1,  2, 2, 1, -1, -2};


int main(){
    bool visited[25][25] = {};
    int distant[25][25] = {};
    int n;
    cin >> n;

    pair<int, int> start_point;
    pair<int, int> target_point;

    cin >> start_point.first >> start_point.second;
    cin >> target_point.first >> target_point.second;

    queue<pair<int,int>> q;
    q.push(start_point);
    visited[start_point.first][start_point.second] = 1;
    distant[start_point.first][start_point.second] = 0;

    while(!q.empty()){
        auto u = q.front();
        q.pop();

        int curr_x = u.first;
        int curr_y = u.second;

        for(int i = 0; i < 8; i++){
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if(nx >= 0 && ny >= 0){
                if (nx < n && ny < n){
                    if (!visited[nx][ny]){
                        q.push({nx,ny});
                        visited[nx][ny] = 1;
                        distant[nx][ny] = distant[curr_x][curr_y] + 1;

                        if (nx == target_point.first && ny == target_point.second){
                            cout << distant[nx][ny] << endl;
                            return 0;
                        }
                    }
                }
            }
        }

        
    }
}