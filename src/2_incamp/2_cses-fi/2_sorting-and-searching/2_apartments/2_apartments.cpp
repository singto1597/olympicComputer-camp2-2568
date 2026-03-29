#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> peoples;

    vector<long long> rooms;
    bool reserve[m] = {};


    for(int i = 0; i < n; i++){
        int people;
        cin >> people;
        peoples.push_back(people);
    }
    for(int i = 0; i < m; i++){
        int room;
        cin >> room;
        rooms.push_back(room);
    }

    sort(peoples.begin(), peoples.end());
    sort(rooms.begin(), rooms.end());

    long long ans = 0;

    long long lastReserve = 0;

    for(int people_i = 0; people_i < n; people_i++){

        for (int room_i = lastReserve; room_i < m; room_i++ ){

            if (peoples[people_i] - rooms[room_i] < (-k)) break;

            
            if (abs(peoples[people_i] - rooms[room_i]) <= k && !reserve[room_i]){
                ans++;
                reserve[room_i] = true;
                lastReserve = room_i;
                
                break;
            }
        }
    }

    cout << ans << endl;

}