#include <iostream>
#include <stdexcept>
using namespace std;

class PriorityQueue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };

    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    void push(int x) {
        //complete this






    }

    int top() const {
        if (empty()) {
            throw out_of_range("Priority queue is empty");
        }
        //complete this






    }

    int pop() {
        if (empty()) {
            throw out_of_range("Priority queue is empty");
        }
        //complete this







    }

    void print() const {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
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

    pq.print();   // 1 2 4 5 8

    cout << "Top = " << pq.top() << endl; // 1
    cout << "Pop = " << pq.pop() << endl; // 1
    cout << "Pop = " << pq.pop() << endl; // 2

    pq.print();   // 4 5 8

    return 0;
}