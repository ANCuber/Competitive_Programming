#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    for (int l = 1; l <= t; l++) {
        int n; cin>>n;
        queue <int> line;
        vector <queue<int> > group(n);
        vector <int> belong(1000005,-1);
        for (int i = 0; i < n; i++) {
            int k; cin>>k;
            for (int j = 0; j < k; j++) {
                int x; cin>>x;
                belong[x] = i;
            }
        }
        int m; cin>>m;
        cout<<"Line #"<<l<<'\n';
        for (int i = 0; i < m; i++) {
            string c; cin>>c;
            if (c[0] == 'E') {
                int x; cin>>x;
                if (belong[x] == -1) {
                    line.push(-1*x);
                } else {
                    if (group[belong[x]].empty()) {
                        line.push(belong[x]);
                    }
                    group[belong[x]].push(x);
                    
                }
            } else {
                if (line.front() < 0) {
                    cout<<-1*line.front()<<'\n';
                    line.pop();
                } else {
                    cout<<group[line.front()].front()<<'\n';
                    group[line.front()].pop();
                    if (group[line.front()].empty()) {
                        line.pop();
                    }
                }
            }
        }
    }
    return 0;
}