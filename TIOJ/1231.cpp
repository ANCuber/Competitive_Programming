#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

struct Food{
    int h, t;
    bool operator<(Food b) {
        return t > b.t;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<Food> fd(n);
    for (int i = 0; i < n; ++i) {
        cin>>fd[i].h>>fd[i].t;
    }
    sort(fd.begin(),fd.end());
    ll ans = 0;
    int k, id = 0; 
    cin>>k;
    priority_queue <int> pq;
    for (int i = k; i >= 1; --i) {
        while(fd[id].t >= i) {
            pq.push(fd[id++].h);
        }
        if (pq.empty()) {
            ans--;
            continue;
        }
        ans += pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
    return 0;
}
