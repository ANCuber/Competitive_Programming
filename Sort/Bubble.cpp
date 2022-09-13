#include <bits/stdc++.h>
using namespace std;

int n;

void bubble_sort(vector <int> &arr) {
    for (int i = n-1; i >= 1; --i) {
        for (int j = 0; j < n-1; ++j) {
            if (arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

int main() {
    cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n;++i) {
        cin>>arr[i];
    }
    bubble_sort(arr);
    for (auto i : arr) cout<<i<<' ';
    cout<<'\n';
    return 0;
}