#include <bits/stdc++.h>
using namespace std;

int n;

void insertion_sort(vector <int> &arr) {
    for (int i = 0; i < n-1; ++i) {
        int minnum = arr[i];
        int index = i;
        for (int j = i+1; j < n; ++j) {
            if (minnum > arr[j]) {
                index = j;
                minnum = arr[j];
            }
        }
        swap(arr[i],arr[index]);
    }
}

int main() {
    cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    insertion_sort(arr);
    for (auto i : arr) cout<<i<<' ';
    cout<<'\n';
    return 0;
}