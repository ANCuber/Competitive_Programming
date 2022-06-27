#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        priority_queue <long long, vector<long long>, greater<long long> > arr;
        for (int i = 0; i < n; ++i) {
            long long x; cin>>x;
            arr.push(x);
        }
        long long cost = 0;
        while(arr.size()>1) {
            long long a = arr.top();
            arr.pop();
            long long b = arr.top();
            arr.pop();
            cost += (a+b);
            arr.push(a+b);
        }
        cout<<cost<<'\n';
    }
    return 0;
}