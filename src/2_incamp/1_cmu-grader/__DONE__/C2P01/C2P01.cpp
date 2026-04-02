#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie();

    string input;
    cin >> input;

    vector<char> chart;

    for (int i = 0; i < input.size(); i++){
        if (chart.empty()){
            chart.push_back(input[i]);
        }
        int j = 0;
        bool isCanPush = 0;
        for(char c : chart){
            if (input[i] <= c){
                chart[j] = input[i];
                isCanPush = 1;
                break;
            }
            j++;
        }
        if(!isCanPush){
            chart.push_back(input[i]);
        }
    } 

    cout << chart.size();


}