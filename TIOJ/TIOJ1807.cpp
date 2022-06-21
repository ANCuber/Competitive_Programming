#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int m, n;
int ctrl = 0;
string ans[2] = {"yes","Yes"};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>m>>n;
    map <pair<int,int>,int> mp;
    int u, v;
    for (int i = 0; i < n; ++i) {
        cin>>u>>v;
        if (ctrl) continue;
        if (u == v) {
            ctrl = 1;
            break;
        }
        else {
            if (mp.find({min(u,v),max(u,v)}) != mp.end()) {
                ctrl = 1;
                break;
            } else {
                mp[{min(u,v),max(u,v)}] = 1;
            }
        }
    }
    cout<<ans[ctrl]<<endl;
    return 0;
}