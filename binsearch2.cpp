#include <iostream>
using namespace std;

int binsearch(const int a[], int size, int target);
int binsearch(const int a[], int min, int max, int target);

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
    return binsearch(a, 0, size - 1, target);
}

int binsearch(const int a[], int min, int max, int target) {
    // If max < min, no remaining entries to search
    if (max < min)
        return -1;

    // Calculate midpoint, it a match, return the midpoint
    int mid = (min + max) / 2;
    if (a[mid] == target)
        return mid;

    // Recursive call to search lower half of array
    if (target < a[mid])
        return binsearch(a, min, mid - 1, target);

    // Recursive call to search upper half of array
    return binsearch(a, mid + 1, max, target);
}