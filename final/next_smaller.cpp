// next_smaller.cpp

// 2) You need to find the next smaller element for each element in an array. For each element in the array, the next smaller element is the first element to its right that is smaller than the current element. If no such element exists, output -1 for that element. Use the following numbers as input: 4, 8, 5, 2, 25;

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElements(const vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    stack<int> s;  // holds indices

    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums[s.top()] >= nums[i]) {
            s.pop();  // pop larger or equal elements
        }

        if (!s.empty()) {
            result[i] = nums[s.top()];  // next smaller to the right
        }

        s.push(i);  // push current index
    }

    return result;
}

int main() {
    vector<int> nums = {4, 8, 5, 12, 1, 2, 25};
    vector<int> result = nextSmallerElements(nums);

    cout << "Next smaller elements:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
