#include <bits/stdc++.h>

using namespace std;

struct Member {
    long long id;
    long long count;
    long long first_idx;
};

bool comp(const Member& a, const Member& b) {
    if (a.count != b.count) {
        return a.count > b.count; 
    }
    return a.first_idx < b.first_idx; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int _ = 0; _ < 5; _++) {
        long long n, c;
        if (!(cin >> n >> c)) break; 

        map<long long, Member> member_data;

        for (int i = 0; i < n; i++) {
            long long id;
            cin >> id;
            
            if (member_data.find(id) == member_data.end()) {
                member_data[id] = {id, 1, i}; 
            } else {
                member_data[id].count++;
            }
        }


        vector<Member> list;
        for (auto const& [key, val] : member_data) {
            list.push_back(val);
        }

        sort(list.begin(), list.end(), comp);


        for (auto m : list) {
            for (int i = 0; i < m.count; i++) {
                cout << m.id << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}