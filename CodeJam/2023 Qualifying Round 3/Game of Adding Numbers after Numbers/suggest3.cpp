#include <iostream>
#include <map>
#include <vector>
using namespace std;

class CustomDataStructure {
private:
    multimap<int, int> smallestElements;  // Multimap for the smallest elements
    multimap<int, int, greater<int>> largestElements;  // Multimap for the largest elements
    long long totalSum;  // Total sum of all elements

public:
    CustomDataStructure() : totalSum(0) {}

    // Query 1: Add an element to the data structure
    void addElement(int element) {
        smallestElements.insert({element, element});
        largestElements.insert({element, element});
        totalSum += element;
    }

    // Query 2: Update w elements in the data structure
    void updateElements(vector<int>& updates) {
        for (int update : updates) {
            auto smallestIt = smallestElements.begin();
            auto largestIt = largestElements.begin();

            // Find the iterators pointing to the element to be updated
            while (smallestIt != smallestElements.end() && smallestIt->second != update) {
                smallestIt++;
            }
            while (largestIt != largestElements.end() && largestIt->second != update) {
                largestIt++;
            }

            // Erase the old value and insert the updated value
            if (smallestIt != smallestElements.end()) {
                totalSum -= smallestIt->second;
                smallestElements.erase(smallestIt);
                smallestElements.insert({update, update});
                totalSum += update;
            }
            if (largestIt != largestElements.end()) {
                totalSum -= largestIt->second;
                largestElements.erase(largestIt);
                largestElements.insert({update, update});
                totalSum += update;
            }
        }
    }

    // Query 3: Get the sum of w largest elements
    long long sumOfWLargest(int w) {
        long long sum = 0;
        auto it = largestElements.begin();
        while (w > 0 && it != largestElements.end()) {
            sum += it->second;
            it++;
            w--;
        }
        return sum;
    }

    // Query 4: Get the sum of w smallest elements
    long long sumOfWSmallest(int w) {
        long long sum = 0;
        auto it = smallestElements.begin();
        while (w > 0 && it != smallestElements.end()) {
            sum += it->second;
            it++;
            w--;
        }
        return sum;
    }
};

int main() {
    CustomDataStructure dataStructure;

    // Query 1: Add elements
    dataStructure.addElement(5);
    dataStructure.addElement(3);
    dataStructure.addElement(8);
    dataStructure.addElement(1);
    dataStructure.addElement(4);

    // Query 2: Update elements
    vector<int> updates = {6, 2};
    dataStructure.updateElements(updates);

    // Query 3: Get the sum of 3 largest elements
    long long sumLargest = dataStructure.sumOfWLargest(3);
    cout << "Sum of 3 largest elements: " << sumLargest << endl;

    // Query 4: Get the sum of 2 smallest elements
    long long sumSmallest = dataStructure.sumOfWSmallest(2);
    cout << "Sum of 2 smallest elements: " << sumSmallest << endl;

    return 0;
}
