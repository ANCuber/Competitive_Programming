#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    priority_queue <int, vector<int>, greater<int> > heap;
    while(t--) {
        int c; cin>>c;
        if (c == 1) {
            int n; cin>>n;
            heap.push(n);
        } else {
            if (!heap.empty()) {
                cout<<heap.top()<<'\n';
                heap.pop();
            } else {
                cout<<"empty!"<<'\n';
            }
        }
    }
    return 0;
}