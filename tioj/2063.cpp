#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

string OPE[2] = {"","-"};
string ope[2] = {"-","+"};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    vector<pair<long double,int> > num(n+2,{1.0,0}); 
    vector<int> s(n+2,0), zero(n+2,0);
    for (int i = 1; i <= n; ++i) {
        cin>>num[i].first;
        if (!num[i].first) {
            zero[i] = 1;
            num[i].first = 1;
            num[i].second = 0;
            continue;
        }
        s[i] = (num[i].first < 0);
        num[i].first = abs(num[i].first);
        while(num[i].first >= 10) {
            num[i].first /= 10;
            num[i].second++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        s[i] += s[i-1];
        zero[i] += zero[i-1];
        num[i].first *= num[i-1].first;
        num[i].second += num[i-1].second;
        while(num[i].first >= 10) {
            num[i].first /= 10;
            num[i].second++;
        }
    }
    cout<<fixed<<setprecision(10);
    while(q--) {
        int l, r; cin>>l>>r;
        if (zero[r]-zero[l]) {
            cout<<0<<endl;
            continue;
        }
        int cur = (s[r]-s[l])%2;
        pair<long double,int> L = num[l], R = num[r];
        
        R.first /= L.first;
        R.second -= L.second;
        
        while(R.first < 1) {
            R.first *= 10;
            R.second--;
        }
        while(R.first >= 10) {
            R.first /= 10;
            R.second++;
        }
        cout<<OPE[cur]<<R.first<<"E"<<ope[R.second>=0]<<R.second<<endl;
    }
    
    return 0;
}
