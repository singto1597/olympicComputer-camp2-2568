#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t, p;
    if (!(cin >> t >> p)) return;

    while (t--) {
        vector<int> a(p);
        for (int i = 0; i < p; i++) {
            cin >> a[i];
        }

        int flips = 0;
        
        for (int bottom = 0; bottom < p; bottom++) {
            
            int max_idx = bottom;
            for (int i = bottom + 1; i < p; i++) {
                if (a[i] > a[max_idx]) {
                    max_idx = i;
                }
            }

            if (max_idx != bottom) {
                if (max_idx != p - 1) {
                    reverse(a.begin() + max_idx, a.end());
                    flips++;
                }

                reverse(a.begin() + bottom, a.end());
                flips++;
            }
        }
        
        cout << flips << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}