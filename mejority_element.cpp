#include <bits/stdc++.h>
using namespace std;

void majority_element(int arr[], int n) {
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int max_count = 0;
    int majority_elem = -1;
    for (auto it : count) {
        if (it.second > max_count) {
            max_count = it.second;
            majority_elem = it.first;
        }
    }

    if (max_count > n / 2) {
        cout << "The majority element is: " << majority_elem << endl;
    } else {
        cout << "No majority element found" << endl;
    }
}

int main() {
    int arr[] = {2, 3, 2, 5, 4, 4, 2, 6, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    majority_element(arr, size);

    return 0;
}
