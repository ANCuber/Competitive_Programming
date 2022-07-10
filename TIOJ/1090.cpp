#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, st; cin>>n>>st;
    int p;
    vector < pii > pos(n);
    for (int i = 0; i < n; ++i) {
        cin>>pos[i].second;
        pos[i].first = abs(pos[i].second-st);
    }
    sort(pos.begin(),pos.end());
    int cur = st;
    int ans = 0;
    int time = 0;
    for (int i = 0; i < n; ++i) {
        time += abs(cur-pos[i].second);
        ans += time;
        cout<<time<<' ';
        cur = pos[i].second;
        cout<<cur<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
