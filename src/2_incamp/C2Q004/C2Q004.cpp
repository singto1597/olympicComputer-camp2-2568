#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        printf("Case %d: ",i);
        double d, v, u;
        cin >> d >> v >> u;
        
        if (v >= u || u == 0 || v == 0){
            cout << "can't determine" << endl;
            continue;
        }

        double time_u_straight, time_u_turn;
        
        time_u_straight = d/u;
        
        double u_sin_zeta;
        u_sin_zeta = sqrt(u*u - v*v);

        time_u_turn = d/u_sin_zeta;

        double difference = time_u_turn - time_u_straight;

        printf("%.3lf\n",difference);

        
    }

        

    return 0; 


}