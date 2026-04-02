#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

vector<int> all_distance;

int n, m;

vector<vector<int>> maze;
vector<vector<int>> visited;

// บน, ล่าง, ซ้าย, ขวา
int dn[] = {-1, 1, 0, 0};
int dm[] = {0, 0, -1, 1};


void dfs_backTracking(pair<int, int> current_path, int current_dist){
    visited[current_path.f][current_path.s] = true;
    if (current_path.f == n && current_path.s == m){
        all_distance.push_back(current_dist);
    }
    else{
        for(int i = 0; i < 4; i++){
            int nn = current_path.f + dn[i];
            int nm = current_path.s + dm[i];
    
            if (nn >= 1 && nn <= n && nm >= 1 && nm <= m){
                if (maze[nn][nm] == 1 && !visited[nn][nm]){
                    dfs_backTracking({nn, nm}, current_dist + 1);
                }
            }
    
        }

    }
    visited[current_path.f][current_path.s] = false;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    maze.resize(n + 5);
    visited.resize(n + 5);
    for(int i = 1; i <= n; i++){
        maze[i].resize(m + 5);
        visited[i].resize(m + 5);
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if (c == 'o') maze[i][j] = 1;
            if (c == 'x') maze[i][j] = 0;
        }

    }

    dfs_backTracking({1,1}, 1);
    // for (int p : all_distance){
    //     cout << p << endl;
    // }

    sort (all_distance.begin(), all_distance.end());

    cout << all_distance.size() << " " << all_distance.back() << " " << all_distance.front() << endl;
}