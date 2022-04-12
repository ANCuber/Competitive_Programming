#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void Report(int val) {
    cout<<val<<' ';
}

void solve(int n) {
    vector <int> arr(n*n);
    arr[0]=1; arr[1]=2; arr[n]=3; arr[n+1]=1;
    int len = 2;
    while(len < n) {
        
        len <<= 1;
    }
    for (int i = 0; i < n*n; ++i) {
        Report(arr[i]);
    }
}

int main() {
    int n; cin>>n;
    solve(n);
    return 0;
}