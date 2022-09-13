#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    queue <int> q;
    for (int i = 1; i <= t; i++) {
        int x; cin>>x;
        if (x == 1) {
            int n; cin>>n;
            q.push(n);
        } else {
            if (q.empty()) cout<<"empty!\n";
            else {
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
    }
    return 0;
}