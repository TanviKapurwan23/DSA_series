#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Heap {
private:
    vector<int> heap;

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    void swap(int index1, int index2) {
        std::swap(heap[index1], heap[index2]);
    }

public:
    void printHeap() {
        cout << "[ ";
        for (size_t i = 0; i < heap.size(); i++) {
            cout << heap[i];
            if (i < heap.size() - 1) {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }

    void insert(int value) {
        heap.push_back(value);
        int current = heap.size() - 1;

        while (current > 0 && heap[current] > heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }
};

int main() {
    Heap* myHeap = new Heap();
    myHeap->insert(99);
    myHeap->insert(72);
    myHeap->insert(61);
    myHeap->insert(58);

    myHeap->printHeap();

    myHeap->insert(100);

    myHeap->printHeap();

    myHeap->insert(75);

    myHeap->printHeap();

    delete myHeap; // Clean up the allocated memory
    return 0;
}
