#include <iostream>
#include <vector>
using namespace std;
int inversion(vector<int>& a, vector<int>& b){
    int count = 0;
    int i = 0;  // a
    int j = 0;  // b

    while(i < a.size() && j < b.size()){
        if(a[i] > b[j]){
            count += (a.size() - i);
            j++;
        }
        else{   // a[i] <= b[j]
            i++;
        }
    }

    return count;
}
void merge(vector<int> a, vector<int> b, vector<int>& res) {
    int i = 0;  // pointer for a
    int j = 0;  // pointer for b
    int k = 0;  // pointer for res

    // merge while both arrays have elements
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }

    // if b is finished, copy remaining a
    if (j == b.size()) {
        while (i < a.size()) {
            res[k++] = a[i++];
        }
    }

    // if a is finished, copy remaining b
    if (i == a.size()) {
        while (j < b.size()) {
            res[k++] = b[j++];
        }
    }
}

int mergeSort(vector<int>& v){
    int count=0;
    int n = v.size();
    if(n == 1) return 0;

    int n1 = n/2, n2 = n - n1;
    vector<int> a(n1), b(n2);

    // copy pasting
    for(int i = 0; i < n1; i++){
        a[i] = v[i];
    }
    for(int i = 0; i < n2; i++){
        b[i] = v[n1 + i];
    }

    // magic aka recursion
    count += mergeSort(a);
    count += mergeSort(b);
    count += inversion(a, b);//count the inversion
    // merge
    merge(a, b, v);
    a.clear();
    b.clear();
    return count;
}

int main(){
    int arr[] = {5,1,3,0,4,9,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);  // same as arr, copy

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout<<endl;
    cout<<mergeSort(v);
}
