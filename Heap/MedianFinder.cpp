#include <queue>
#include <functional>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap; // Max heap to store the smaller half of numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min heap to store the larger half of numbers

public:
    MedianFinder() {
        // Constructor to initialize the MedianFinder object
    }
    
    void addNum(int num) {
        // Function to add a number to the data structure
        
        // If maxHeap is empty or the number is smaller than or equal to the top of maxHeap, insert into maxHeap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            // Otherwise, insert into minHeap
            minHeap.push(num);
        }

        // Balance the heaps if necessary
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // Function to find the median of all elements added so far
        
        if (maxHeap.size() == minHeap.size()) {
            // If both heaps have equal size, median is the average of their tops
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            // If maxHeap has one more element, its top is the median
            return maxHeap.top();
        }
    }
};
