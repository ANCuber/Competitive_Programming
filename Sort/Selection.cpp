#include <bits/stdc++.h>
using namespace std;

int n;

void selection_sort(vector <int> &arr) {
    for (int i = n-1; i >= 0; --i) {
        int max = -1e9;
        int index;
        for (int j = 0; j <= i; ++j) {
            if (max < arr[j]) {
                max = arr[j];
                index = j;
            }
        }
        int buffer = arr[i];
        arr[i] = max;
        arr[index] = buffer;
    }
}

int main() {
    cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    selection_sort(arr);
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' ';
        cout<<arr[i];
    }
    cout<<'\n';
    return 0;
}