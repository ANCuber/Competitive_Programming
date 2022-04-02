#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector <int> &arr, int n) {
    if (n <= 1) return;
    int leng1 = n/2;
    int leng2 = n-leng1;
    vector <int> arr1(arr.begin(), arr.begin()+leng1);
    vector <int> arr2(arr.begin()+leng1,arr.end());
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