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
        int left_index  = leftChild (index);
        int right_index = rightChild(index);

        int smallest = index;
        
        if (left_index  < (int)heap.size() && heap[left_index]  < heap[smallest]) smallest = left_index;
        if (right_index < (int)heap.size() && heap[right_index] < heap[smallest]) smallest = right_index;

        if (smallest != index){
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
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
        
        int return_value = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) heapifyDown(0);

        return return_value;

    }

    void build_heap(const vector<int>& a) {
        heap = a;
        //implement this

        for (int i = (int)heap.size()/2 - 1; i >= 0; i--){
            heapifyDown(i);
        }



        

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