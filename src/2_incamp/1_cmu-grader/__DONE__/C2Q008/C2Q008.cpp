#include <bits/stdc++.h>

using namespace std;
bool visited[20][20] = {};

struct Point{
    int x;
    int y;
};

int dx[4] = {-1, 0, 1,  0};
int dy[4] = { 0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    int arr[n][m] = {};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int start_x, start_y;
    cin >> start_x >> start_y;

    int color;
    cin >> color;

    queue<Point> s;
    s.push({start_x, start_y});
    // visited[start]= true;

    int base_color = arr[start_x][start_y];

    while(!s.empty()){
        Point u = s.front();
        s.pop();
        
        if (visited[u.x][u.y]) continue;

        visited[u.x][u.y] = true;

        arr[u.x][u.y] = color;

        for (int i = 0; i < 4; i++){
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&!visited[nx][ny] && arr[nx][ny] == base_color){
                s.push({nx,ny});
            }
        }

    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}