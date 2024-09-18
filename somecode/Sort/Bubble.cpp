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

bool cmp(long long a, long long b) {
    if (a > b) return true;
    return false;
}

int main() {
    
    vector<long long> arr(n+5); arr[1]~arr[n];
    sort(arr.begin()+1,arr.begin()+1+n,cmp);
    
    cin>>n;
        vector <int> arr(n);
        for (int i = 0; i < n;++i) {
            cin>>arr[i];
        }
        //bubble_sort(arr);
        sort(arr.begin(),arr.end());
        for (int i = 0; i < n; ++i) { 
            if (i) cout<<' ';
            cout<<arr[i];
        }
        cout<<'\n';
    return 0;
}
