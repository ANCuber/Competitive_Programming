#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string cmd;
    int x, ksz = 1;
    priority_queue <int> k;
    priority_queue <int, vector<int>, greater<int> > pq;
    while(cin>>cmd && cmd != "END") {
        if (cmd[0] == 'P') {
            cin>>x;
            k.push(x);
            if (k.size() > ksz) {
                pq.push(k.top());
                k.pop();
            }
        } else if (cmd[0] == 'G') {
            if (ksz == k.size()) {
                cout<<k.top()<<endl;
                ksz++;
                if (!pq.empty()) {
                    k.push(pq.top());
                    pq.pop();
                }
            }
        } else {
            k = priority_queue <int>(); 
            pq = priority_queue <int, vector<int>, greater<int> >(); 
            ksz = 1;
        }
    }
    return 0;
}

//cool skill
