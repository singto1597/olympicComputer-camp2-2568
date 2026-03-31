#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class PriorityQueue {
private:
    vector<int> data;

public:
    bool empty() const {
        return data.empty();
    }

    void push(int x) {
        //complete this
        data.push_back(x);

    }

    int top() const {
        //complete this
        int min_index = 0;

        for (int i = 0; i < (int)data.size(); i++){
            if (data[i] < data[min_index]) min_index = i;
        }

        return data[min_index];





    }

    int pop() {
        //complete this

        int min_index = 0;

        for (int i = 0; i < (int)data.size(); i++){
            if (data[i] < data[min_index]) min_index = i;
        }

        int return_value = data[min_index];
        data.erase(data.begin() + min_index);

        return return_value;





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

    cout << "Current data: ";
    pq.print();

    cout << "Top = " << pq.top() << endl;   // 1
    cout << "Pop = " << pq.pop() << endl;   // 1
    cout << "Pop = " << pq.pop() << endl;   // 2

    cout << "Remaining: ";
    pq.print();

    return 0;
}