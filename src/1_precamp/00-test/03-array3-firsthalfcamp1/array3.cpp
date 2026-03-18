#include <bits/stdc++.h>

using namespace std;

int maze[120][120] = {0};
bool visited[120][120] = {0};
int dist[120][120] = {0};
bool ans[120][120] = {0};

// บน, ล่าง, ซ้าย, ขวา
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

pair<int, int> from_path[120][120];

//แถวที่ x คอลัมที่ y

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= m; j++){
            cin >> maze[i][j];
            
        }
    }
    if (maze[1][1] == 0 || maze[n][m] == 0){
        cout << "NO" << endl;
        return 0;
    }

    queue<pair<int, int>> q;

    q.push({1,1});
    visited[1][1] = true;
    dist[1][1] = 0;
    from_path[1][1] = {-1, -1};

    while (!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;
        if (x == n && y == m){
            cout << "YES " << dist[x][y] << endl;
            int curr_x = n, curr_y = m;
            ans[curr_x][curr_y] = 1;
            while (curr_x != -1 && curr_y != -1){
                pair<int,int> parent = from_path[curr_x][curr_y];
                curr_x = parent.first;
                curr_y = parent.second;
                if (curr_x != -1 && curr_y != -1) {
                    ans[curr_x][curr_y] = 1;
                }
            }
            for (int i = 1; i <= n ; i++){
                for (int j = 1; j <= m; j++){
                    cout << ans[i][j] << " ";
                    
                }
                cout << endl;
            }
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if (maze[nx][ny] == 1 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    from_path[nx][ny] = {x, y};

                    q.push({nx,ny});
                }
            }
        }
    }

    cout << "NO" << endl;

}