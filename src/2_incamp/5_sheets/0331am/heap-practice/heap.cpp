#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// min heap
class Heap {
private:
    vector<int> heap;

    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

    void heapifyUp(int index) {
        if (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        //implement this










    }

public:
    bool empty() const {
        return heap.empty();
    }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp((int)heap.size() - 1);
    }

    int remove_min() {
        //implement this









    }

    void build_heap(const vector<int>& a) {
        heap = a;
        //implement this





        

    }
};

int main() {
    Heap h;
    h.insert(3);
    h.insert(1);
    h.insert(6);
    h.insert(5);
    h.insert(2);
    h.insert(4);

    while (!h.empty()) {
        cout << h.remove_min() << endl;
    }

    return 0;
}