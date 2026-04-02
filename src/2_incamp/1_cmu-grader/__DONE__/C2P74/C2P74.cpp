#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    set<int> home_numbers;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        home_numbers.insert(number); 
    }


    vector<int> v(home_numbers.begin(), home_numbers.end());

    if (v.size() == 1) {
        cout << "1\n" << v[0] << " " << v[0] << "\n";
        return 0;
    }


    int max_len = 0;
    int best_start = 0, best_end = 0;

    int current_start = v[0];
    int current_len = 1;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1] + 1) {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                best_start = current_start;
                best_end = v[i-1];
            }
            current_start = v[i];
            current_len = 1;
        }
    }

    if (current_len > max_len) {
        max_len = current_len;
        best_start = current_start;
        best_end = v.back();
    }

    cout << max_len << "\n";
    cout << best_start << " " << best_end << "\n";

    return 0;
}