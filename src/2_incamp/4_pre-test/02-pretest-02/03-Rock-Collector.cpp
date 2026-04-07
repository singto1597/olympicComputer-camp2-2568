#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<char, int> rock_value;
    rock_value['F'] = 1;
    rock_value['G'] = 3;
    rock_value['S'] = 2;

    int k;
    cin >> k;

    for (int _ = 0; _ < k; _++){
        string rock_order = "";
        
        cin >> rock_order;
        
        int n = rock_order.size();
    
        vector<int> rock_max(n + 5, 1);
    
        int rock_max_number = 1;
        

        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (rock_value[rock_order[j]] <= rock_value[rock_order[i]]){
                    // cout << rock_order[j] << " " << rock_order[i] << endl;
                    rock_max[i] = max(rock_max[j] + 1, rock_max[i]);
                    if (rock_max[i] > rock_max_number) rock_max_number = rock_max[i];
                }
            }
        }
    
        cout << rock_max_number << endl;

    }


}