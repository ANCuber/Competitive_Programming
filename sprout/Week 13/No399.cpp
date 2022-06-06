#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

unsigned ll dis(pair<ll,ll> &p1, pair<ll,ll> &p2) {
    return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}

unsigned ll fact(ll c) {
    return (unsigned ll) (c*(c-1))/2;
}

int main() {
    int n; cin>>n;
    vector <pair<ll,ll> > point(n); 
    for (int i = 0; i < n; ++i) {
        cin>>point[i].first>>point[i].second;
    }
    unordered_map <ll,int> mp; 
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            unsigned ll distance = dis(point[i],point[j]);
            if (mp.find(distance) == mp.end()) mp[distance] = 1;
            else mp[distance]++;
            //cout<<i<<' '<<j<<' '<<distance<<endl;
        }
    }
    unsigned ll ans = 0;
    unordered_map<ll,int>::iterator iter;
    for (iter = mp.begin(); iter != mp.end(); iter++) {
        ans += fact(iter->second);
    }
    cout<<ans<<endl;
    return 0;
}