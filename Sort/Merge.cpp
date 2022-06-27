#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector <int> &arr, int n) {
    if (n <= 1) return;
    int leng1 = n/2;
    int leng2 = n-leng1;
    vector <int> arr1(arr.begin(), arr.begin()+leng1);
    vector <int> arr2(arr.begin()+leng1,arr.end());
    merge_sort(arr1,leng1);
    merge_sort(arr2,leng2);
    int temp[n];
    int len = 0;
    int p1 = 0, p2 = 0;
    while(len < n) {
        if (p2 == leng2 || arr1[p1] <= arr2[p2]) {
            temp[len++] = arr1[p1++];
        } else {
            temp[len++] = arr2[p2++];
        }
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = temp[i];
    }
    return;
}

int main() {
    int n; cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    merge_sort(arr,n);
    for (auto i : arr) cout<<i<<' ';
    cout<<'\n';
    return 0;
}