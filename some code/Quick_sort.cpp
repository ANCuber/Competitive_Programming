#include <bits/stdc++.h>
using namespace std;

int n;

void quick_sort(vector <int> &arr) {

}

int main() {
    cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    quick_sort(arr);
    for (auto i : arr) cout<<i<<' ';
    cout<<'\n';
    return 0;
}