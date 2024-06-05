#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, L, K; cin>>N>>L>>K;    
    for (int i = 1; i <= N; ++i) {
        string S; cin>>S;
        S = '*'+S;
        vector<int> cnt(30,0);
        int ans = 0;
        if (K == 1) {
            cout<<L<<endl;
        } else if (K%2) {//1010101...
            for (int j = 1; j <= L; j += 2) cnt[S[j]-'a']++;
            ans = *max_element(cnt.begin(),cnt.end());
            fill(cnt.begin(),cnt.end(),0);
            for (int j = 2; j <= L; j += 2) cnt[S[j]-'a']++;
            cout<<ans+*max_element(cnt.begin(),cnt.end())<<endl;
        } else {//11111...
            for (int j = 1; j <= L; ++j) cnt[S[j]-'a']++;
            cout<<*max_element(cnt.begin(),cnt.end())<<endl;
        }
    }
    return 0;
}
