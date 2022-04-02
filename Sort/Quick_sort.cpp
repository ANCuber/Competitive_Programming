#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector <int> &arr, int n) {
    if (n <= 1) return;
    int pivot_index = rand()%n;
    int pivot = arr[pivot_index];
    swap(arr[pivot_index],arr[n-1]);
    int len = 0;
    for (int i = 0; i < n-1; ++i) {
        if (arr[i] < pivot) {
            swap(arr[i],arr[len++]);
        }
    }
    swap(arr[len], arr[n-1]);
    int len2 = len + 1;
    for (int i = len2; i < n; ++i) {
        if (arr[i] == pivot) {
            swap(arr[i], arr[len2++]);
        }
    }

    vector <int> arr2(arr.begin()+len2, arr.end());

    quick_sort(arr, len);
    quick_sort(arr2, n-len2);
}

int main() {
    int n; cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    quick_sort(arr,n);
    for (auto i : arr) cout<<i<<' ';
    cout<<'\n';
    return 0;
}