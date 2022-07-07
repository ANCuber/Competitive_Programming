#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    priority_queue <int,vector<int>,greater<int> > pq;
    for (int i = 0; i < m; ++i) {
        pq.push(arr[i]);
    }
    for (int i = m; i < n; ++i) {
        int cur = pq.top();
        pq.pop();
        pq.push(arr[i]+cur);
    }
    while(pq.size() != 1) {
        pq.pop();
    }
    cout<<pq.top()<<endl;
    return 0;
}
