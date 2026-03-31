#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int q;
    cin >> q;
    stack<int> s;
    for (int i = 0; i < q; i++){
        int c;
        cin >> c;
        int number;
        switch (c){
            case 1:
                cin >> number;
                s.push(number);
                break;
            
            case 2:
                if(s.empty()) cout << "-1" << "\n";
                else {
                    cout << s.top() << "\n";
                    s.pop();
                }
                break;
            
            case 3:
                cin >> number;
                if(s.empty()) cout << "-1" << "\n";
                else{
                    stack<int> s_temp;
                    bool isVisited = false;
                    while(!s.empty()){
                        int temp = s.top();
                        s.pop();
                        if (temp == number){
                            cout << number << "\n";
                            isVisited = true;
                            break;
                        }
                        s_temp.push(temp);
                    }
                    while(!s_temp.empty()){
                        int temp = s_temp.top();
                        s_temp.pop();
                        
                        s.push(temp);
                    }
                    if (!isVisited){
                        cout << "-1\n" ;

                    }
                }

                break;
        }
    }
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}