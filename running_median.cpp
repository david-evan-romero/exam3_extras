#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // Needed for decimal precision formatting

using namespace std;

// The core data structure logic using two heaps
class MedianFinder {
    // Max heap for the lower half (ensures top is the largest element of the lower half)
    priority_queue<int> lo; 
    
    // Min heap for the upper half (ensures top is the smallest element of the upper half)
    priority_queue<int, vector<int>, greater<int>> hi; 

public:
    void addNum(int num) {
        // 1. Insert: Always insert into the Max Heap (lo) first.
        lo.push(num);
        
        // 2. Transfer: Move the largest element of 'lo' (lo.top()) to 'hi' 
        // to maintain the property that all elements in lo <= all elements in hi.
        hi.push(lo.top());
        lo.pop();
        
        // 3. Balance: Ensure lo has size >= hi, and lo.size() - hi.size() <= 1.
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if (lo.size() == hi.size()) {
            // Even number of elements: average of the two middle elements
            return ((double)lo.top() + hi.top()) / 2.0;
        } else {
            // Odd number of elements: the middle element (which is always in lo)
            return (double)lo.top();
        }
    }
};

// The function required by the HackerRank problem statement
vector<double> runningMedian(vector<int> a) {
    MedianFinder mf;
    vector<double> results;

    for (int num : a) {
        mf.addNum(num);
        results.push_back(mf.findMedian());
    }
    return results;
}

// The main function structure provided by the template (you might need to adjust this depending on the exact template)
int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<double> results = runningMedian(a);
    
    // Formatting the output to one decimal place as required
    cout << fixed << setprecision(1);
    for (double median : results) {
        cout << median << "\n";
    }
    
    return 0;
}
