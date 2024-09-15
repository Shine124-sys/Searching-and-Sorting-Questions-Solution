#include <bits/stdc++.h>
using namespace std;

void printZeroSumSubarrays(int arr[], int n) {
    unordered_map<int, vector<int>> prefixSumMap;
    int prefixSum = 0;

    // Traverse the array
    for (int i = 0; i < n; ++i) {
        // Update the prefix sum
        prefixSum += arr[i];

        // If prefix sum is zero, subarray (0, i) has sum zero
        if (prefixSum == 0) {
            cout << "Subarray [0, " << i << "]" << endl;
        }

        // If prefix sum already exists in the map, it means we found a subarray with zero sum
        if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
            // Traverse through all the previous indices where this prefix sum was seen
            for (auto it = prefixSumMap[prefixSum].begin(); it != prefixSumMap[prefixSum].end(); ++it) {
                cout << "Subarray [" << (*it + 1) << ", " << i << "]" << endl;
            }
        }

        // Insert the prefix sum into the map
        prefixSumMap[prefixSum].push_back(i);
    }
}

int main() {
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printZeroSumSubarrays(arr, n);

    return 0;
}
