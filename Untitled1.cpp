#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> arr(5);
    for (int i = 0; i < 5; ++i) {
        arr[i] = i;
    }
    vector <int> arr1(arr.begin(),arr.begin()+3);
    vector <int> arr2(arr.begin()+3,arr.end());
    for (auto i : arr1) cout<<i<<' ';
    cout<<endl;
    for (auto i : arr2) cout<<i<<' ';
    cout<<endl;
    return 0;
}