#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

vector<int> bit;
map <int,int> mp;

void update(int pos, int x) {
    for (;pos <= mp.size(); pos += (pos & -pos)) {
        bit[pos] = max(bit[pos],x);
    }
}

int query(int x) {
    int ret = 0;
    for (;x>0;x -= (x & -x)) {
        ret = max(ret,bit[x]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <pair<int,int> > fruit(n+1);
    int ans = 0;
    fruit[0] = {0,0};
    for (int i = 1; i <= n; ++i) {
        cin>>fruit[i].first>>fruit[i].second;
    }
    sort(fruit.begin(),fruit.end(),[](const pair<int,int> &a,
    const pair<int,int> &b){return a.second < b.second;});
    for (int i = 1; i <= n; ++i) {
        if (!mp.count(fruit[i].second)) {
            mp.insert({fruit[i].second,mp.size()+1});
        }
    }
    bit.resize(mp.size()+1,0);
    int maxn = 0;
    
    sort (fruit.begin(),fruit.end());
    for (int i = 1; i <= n; ++i) {
        int cur = query(mp[fruit[i].second]);
        maxn = max(maxn,cur+1);
        update(mp[fruit[i].second],cur+1);
    }
    cout<<maxn<<endl;
    return 0;
}