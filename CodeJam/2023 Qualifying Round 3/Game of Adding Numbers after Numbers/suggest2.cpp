#include <bits/stdc++.h>
using namespace std;

class CustomDataStructure {
private:
    set<int> elements;           // Balanced Binary Search Tree (BBST) to store unique elements
    vector<long long> prefixSum; // Prefix sum array to store cumulative sums

public:
    CustomDataStructure() {
        prefixSum.push_back(0); // Initialize prefix sum with 0
    }

    // Query 1: Add an element to the data structure
    void addElement(int element) {
        elements.insert(element);
        updatePrefixSum(element);
    }

    // Query 2: Update w elements in the data structure
    void updateElements(vector<int>& updates) {
        for (int update : updates) {
            // Remove the old value and insert the updated value
            elements.erase(update);
            elements.insert(update);
            updatePrefixSum(update);
        }
    }

    // Query 3: Get the sum of w largest elements
    long long sumOfWLargest(int w) {
        if (w >= elements.size()) {
            // Sum all elements
            return prefixSum.back();
        } else {
            auto it = elements.rbegin();
            advance(it, w); // Move the iterator to the (w+1)-th largest element
            return prefixSum[std::distance(elements.begin(), it)];
        }
    }

    // Query 4: Get the sum of w smallest elements
    long long sumOfWSmallest(int w) {
        if (w >= elements.size()) {
            // Sum all elements
            return prefixSum.back();
        } else {
            auto it = elements.begin();
            advance(it, w); // Move the iterator to the (w+1)-th smallest element
            return prefixSum[distance(elements.begin(), it)];
        }
    }

private:
    // Update the prefix sum array after adding or updating an element
    void updatePrefixSum(int element) {
        prefixSum.push_back(prefixSum.back() + element);
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
