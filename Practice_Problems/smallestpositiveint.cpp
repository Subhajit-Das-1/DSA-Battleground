#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,4,5,6,9,12};
    int n = 7;

    // for(int i=0;i<n;i++){
    //     if(arr[i]!=i+1){
    //         cout<<i+1;
    //         break;
    //     }
    // }

    int lo = 0;
    int hi = n - 1;
    int ans = -1;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(arr[mid] == mid + 1) {
            lo = mid + 1;
        }
        else {
            ans = mid + 1;
            hi = mid - 1;
        }
    }

    cout << ans;
}
