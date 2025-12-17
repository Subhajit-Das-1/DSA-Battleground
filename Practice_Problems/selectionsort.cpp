#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {5, 3, 1, 4, 2};
    int n = 5;

    // Print original array
    for(int ele : arr){
        cout << ele << " ";
    }
    cout << endl;


    // --------------------
    // SELECTION SORT
    // --------------------
    for(int i = 0; i < n - 1; i++){
        int mn = INT_MAX;   // Minimum element
        int mindex = -1;    // Index of minimum

        // Find minimum element in remaining array
        for(int j = i; j < n; j++){
            if(arr[j] < mn){
                mn = arr[j];
                mindex = j;
            }
        }

        // Place minimum at correct position
        swap(arr[i], arr[mindex]);
    }


    // Print sorted array
    cout << "After Selection Sort: ";
    for(int ele : arr){
        cout << ele << " ";
    }
    cout << endl;