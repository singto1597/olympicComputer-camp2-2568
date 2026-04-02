#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // int  int  int
    // หิว  ลำดับ  ID 
    set<tuple<int, int, int>, greater<tuple<int,int,int>>> order_queue;
    
    map<int, tuple<int, int, int>> id_order_queue;

    int order_current = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int choise;
        cin >> choise;

        int id, number;
        

        switch(choise){
            case 1:
                cin >> id >> number;
                order_current++;
                order_queue.insert ( {number, order_current * -1, id} );
                id_order_queue[id] = {number, order_current * -1, id};
                break;


            case 2: {
                cin >> id >> number;
                if (!order_queue.empty()){
                    order_queue.erase(id_order_queue[id]);

                    int order_temp = get<1>(id_order_queue[id]);
    
                    id_order_queue[id] = {number, order_temp, id};
    
                    order_queue.insert(id_order_queue[id]);
                }



                break;
            }

            case 3: {
                tuple<int, int, int> customer_temp = *order_queue.begin();
                if (order_queue.empty()){
                    cout << "no customer" << endl;
                }
                else{
                    cout << get<2> (customer_temp) << endl;
                    order_queue.erase(order_queue.begin());

                }
                break;
            }

        }
    }
}