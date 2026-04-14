#include <bits/stdc++.h>

using namespace std;

vector<int> weights;
vector<long long> hell_reactors;
vector<long long> heaven_reactors;
long long hell_reactor_max = 0;

vector<vector<long long>> dp;

long long find_max_energy(long long current_i, long long current_hell_weight){
    
    if (current_hell_weight > hell_reactor_max){
        return -1e18;
    }

    if (dp[current_i][current_hell_weight] != 0) return dp[current_i][current_hell_weight];

    if (current_i == 0){
        if (weights[0] + current_hell_weight > hell_reactor_max){
            return dp[current_i][current_hell_weight] = heaven_reactors[0];
        }
        else{
            return dp[current_i][current_hell_weight] = max(heaven_reactors[0],hell_reactors[0]);
        }

    }




    return  dp[current_i][current_hell_weight] = max(hell_reactors[current_i] + find_max_energy(current_i - 1, current_hell_weight + weights[current_i]),
               heaven_reactors[current_i] + find_max_energy(current_i - 1, current_hell_weight)
            );
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;

    weights.assign(n + 5, 0);
    hell_reactors.assign(n + 5, 0);
    heaven_reactors.assign(n + 5, 0);
    dp.assign(n + 5, vector<long long>(130000, 0));



    // น้ำหนักรวมของวัตถุดิบในเตา hell ต้องไม่มากกว่าน้ำหนักรวมของวัตถุดิบในเตา heaven
    // whell <= wheaven
    // whell <= wtotal - whell
    // 2whell <= wtotal
    // *whell <= wtotal / 2*
    long long total_weight = 0;

    for (int i = 0; i < n; i++){
        long long weight_i, hell_reactor_i, heaven_reactor_i;
        cin >> weight_i;
        cin >> hell_reactor_i;
        cin >> heaven_reactor_i;

        weights[i] = weight_i;
        hell_reactors[i] = hell_reactor_i;
        heaven_reactors[i] = heaven_reactor_i;

        total_weight += weight_i;
    } 

    hell_reactor_max = total_weight / 2;


    cout << find_max_energy(n - 1, 0) << endl;


}