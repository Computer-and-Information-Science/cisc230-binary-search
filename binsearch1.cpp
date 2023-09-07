#include <iostream>
using namespace std;

int binsearch(const int a[], int size, int target);

int main () {

    int array[] = { 3, 6, 8, 11, 14, 17, 19, 22, 27, 33, 39, 42 };
    int size = sizeof(array) / sizeof(int);

    int i = 0;
    for (auto n: array)
        cout << " " << i++ << ":" << n;
    cout << endl;

    int target;
    cout << "Enter target value: ";
    cin >> target;

    int index = binsearch(array, size, target);
    if (index >= 0)
        cout << "Target found at location " << index << ".\n";
    else
        cout << "Target not found.\n";
}

int binsearch(const int a[], int size, int target) {
    // Initial min and max index to search
    int min = 0, max = size - 1;

    // Remain in loop while there remains array segments to search
    while (min <= max) {
        // Calculate the midpoint
        int mid = (min + max) / 2;

        // If found, return the index
        if (a[mid] == target)
            return mid;

        // Adjust search range based on target relation to midpoint
        if (target < a[mid])
            max = mid - 1; // Adjust upper end of search range
        else
            min = mid + 1; // Adjust lower end of search range
    }

    return -1; // Target not found
}
