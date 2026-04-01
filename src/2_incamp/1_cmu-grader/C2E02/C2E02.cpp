#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++){
        stack<int> st;
        queue<int> qq;
        priority_queue<int> pq;
        bool st_cando = true;
        bool qq_cando = true;
        bool pq_cando = true;
        int n;
        cin >> n;
        for (int i = 0; i < n; i ++){
            int choise;
            int value;
            cin >> choise >> value;

            switch (choise){
                case 1:
                    if (st_cando) st.push(value);
                    if (qq_cando) qq.push(value);
                    if (pq_cando) pq.push(value);
                    break;


                case 2: {
                    if (st_cando) {
                        if (st.empty() || st.top() != value) {
                            st_cando = false;
                        } else {
                            st.pop();
                        }
                    }
                    

                    if (qq_cando) {
                        if (qq.empty() || qq.front() != value) {
                            qq_cando = false;
                        } else {
                            qq.pop();
                        }
                    }
                    

                    if (pq_cando) {
                        if (pq.empty() || pq.top() != value) {
                            pq_cando = false;
                        } else {
                            pq.pop();
                        }
                    }

                    break;
                }
                    



            }
        }

        int number = 0;
        number += st_cando;
        number += qq_cando;
        number += pq_cando;

        if (number == 0){
            cout << "impossible" << endl;
        }
        else if (number == 1){
            if (st_cando){
                cout << "stack" << endl;
            }
            if (qq_cando){
                cout << "queue" << endl;
            }
            if (pq_cando){
                cout << "priority queue" << endl;
            }
        }
        else{
            cout << "not sure" << endl;
        }
        

    }



}