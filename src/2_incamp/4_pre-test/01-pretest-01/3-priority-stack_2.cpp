#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int q;
    cin >> q;
    stack<int> s;
    set<int> active;
    for (int i = 0; i < q; i++){
        int c;
        cin >> c;
        int number;
        switch (c){
            case 1:
                cin >> number;
                s.push(number);
                active.insert(number);
                break;
            
            case 2:
                while (!s.empty() && active.find(s.top()) == active.end()) {
                    s.pop();
                }
                if(s.empty()) cout << "-1" << "\n";
                else {
                    int top_val = s.top();
                    cout << top_val << "\n";
                    s.pop();
                    active.erase(top_val);
                }
                break;
            
            case 3:
                cin >> number;
                if (active.find(number) != active.end()){
                    cout << number << "\n";
                    active.erase(number);
                }
                else{
                    cout << "-1" << endl;
                }

                break;
        }
    }
    
    while (!s.empty()){
        if (active.find(s.top()) != active.end()){
            cout << s.top() << " ";
            active.erase(s.top());
        }
        s.pop();
    }
    cout << endl;
    return 0;
}