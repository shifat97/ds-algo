#include <iostream>
#include <vector>
using namespace std;

int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}


int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;

    int resultIterative = binarySearchIterative(arr, target);
    if (resultIterative != -1) {
        cout << "Element found at index: " << resultIterative << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}