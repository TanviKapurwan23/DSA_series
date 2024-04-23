// combination of a hash map (unordered_map in C++) and a vector

#include <unordered_map>
#include <vector>
#include <cstdlib> // For rand()
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> indexMap; // Map to store element-index mapping
    vector<int> elements; // Vector to store elements
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (indexMap.find(val) != indexMap.end()) {
            return false; // Element already exists
        }
        indexMap[val] = elements.size(); // Map val to its index in the vector
        elements.push_back(val); // Insert val into the vector
        return true;
    }
    
    bool remove(int val) {
        if (indexMap.find(val) == indexMap.end()) {
            return false; // Element doesn't exist
        }
        int index = indexMap[val]; // Get the index of val in the vector
        int lastElement = elements.back(); // Get the last element in the vector
        elements[index] = lastElement; // Replace val with the last element
        indexMap[lastElement] = index; // Update the index of lastElement in the map
        elements.pop_back(); // Remove the last element
        indexMap.erase(val); // Erase val from the map
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % elements.size(); // Generate a random index
        return elements[randomIndex]; // Return the element at the random index
    }
};
