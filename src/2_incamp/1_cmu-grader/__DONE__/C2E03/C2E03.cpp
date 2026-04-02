#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++){
        int n;
        cin >> n;

        multiset<int> bills;

        int ans = 0;

        for (int i = 0; i < n; i++){
            int bill_number;
            cin >> bill_number;
            for (int k = 0; k < bill_number; k++){
                int customer;
                cin >> customer;
                bills.insert(customer);
            }
            if (bills.size() >= 2){
                auto itMax = prev(bills.end());
                auto itMin = bills.begin();
            
                ans += (*itMax - *itMin);

                bills.erase(itMax);

            

                bills.erase(itMin);

            }
        }
        cout << ans << endl;
    }
}