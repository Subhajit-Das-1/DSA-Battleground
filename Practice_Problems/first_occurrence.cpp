#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,1,2,2,3,3,3,4,5,5,9,9,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;          // element whose first occurrence we want

    int lo = 0;
    int hi = n - 1;
    bool flag = false;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == x) {
            // check if this is the first occurrence
            if (mid == 0 || arr[mid - 1] != x) {
                cout << mid;   // index of first occurrence
                flag = true;
                break;
            } else {
                hi = mid - 1;  // go left
            }
        } else if (arr[mid] < x) {
            lo = mid + 1;
        } else { // arr[mid] > x
            hi = mid - 1;
        }
    }

    if (flag == false)
        cout << -1;     // not found

    return 0;
}
