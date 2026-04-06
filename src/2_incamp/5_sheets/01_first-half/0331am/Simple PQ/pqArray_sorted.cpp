#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class PriorityQueue {
private:
    vector<int> data;   // kept in descending order

public:
    bool empty() const {
        return data.empty();
    }

    void push(int x) {
        //complete ethis




    }

    int top() const {
        //complete this





    }

    int pop() {
        //complete this





    }

    void print() const {
        for (int x : data) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);
    pq.push(4);

    pq.print();   // 8 5 4 2 1

    cout << "Top = " << pq.top() << endl; // 1
    cout << "Pop = " << pq.pop() << endl; // 1
    cout << "Pop = " << pq.pop() << endl; // 2

    pq.print();   // 8 5 4

    return 0;
}