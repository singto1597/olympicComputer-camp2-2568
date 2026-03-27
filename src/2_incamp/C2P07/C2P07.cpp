#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    pair<int,int> coordinate[n];
    pair<double, pair<int,int>> displacement_coordinate[n];
    for(int i = 0; i < n; i++){
        cin >> coordinate[i].first >> coordinate[i].second;
        displacement_coordinate[i].first = sqrt(abs((
            coordinate[i].first * coordinate[i].first) + 
            (coordinate[i].second * coordinate[i].second)));
        displacement_coordinate[i].second = coordinate[i];
        // cout << displacement_coordinate[i].first << endl;
    }
    sort(displacement_coordinate, displacement_coordinate + n);

    for(int i = 0; i < n; i++){

        cout << "(" <<displacement_coordinate[i].second.first << ", " << displacement_coordinate[i].second.second << ")"<< endl;
    }
}