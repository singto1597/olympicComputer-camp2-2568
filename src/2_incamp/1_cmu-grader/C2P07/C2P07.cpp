#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<long long, int, pair<int,int>> a, tuple<long long, int, pair<int,int>> b){
    if (get<0>(a) != get<0>(b)){
        return get<0>(a) < get<0>(b);
    }
    else {
        if (get<0>(a) == get<0>(b)){
            return get<1>(a) < get<1>(b);
        }
        
    }
    return 0;

}

int main(){
    int n;
    cin >> n;

    pair<int,int> coordinate[n];
    tuple<long long, int, pair<int,int>> displacement_coordinate[n];
    for(int i = 0; i < n; i++){
        cin >> coordinate[i].first >> coordinate[i].second;
        long long x = coordinate[i].first ;
        long long y = coordinate[i].second ;
        get<0>(displacement_coordinate[i]) = (x * x) + (y * y);
        get<1>(displacement_coordinate[i]) = i + 1;
        get<2>(displacement_coordinate[i]) = coordinate[i];
        // cout << displacement_coordinate[i].first << endl;
    }
    sort(displacement_coordinate, displacement_coordinate + n, comp);

    for(int i = 0; i < n; i++){

        cout << "(" << get<2>(displacement_coordinate[i]).first << ", " << get<2>(displacement_coordinate[i]).second << ")"<< endl;
    }
}