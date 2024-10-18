#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M, K; cin>>N>>M>>K;
    K -= M;
    int L, Ex, Sm; cin>>L>>Ex>>Sm;
    int T; cin>>T;
    vector<int> S(M+2);
    p_q < pair<int,pii> > pq;
    for (int i = 1; i <= M; ++i) cin>>S[i];
    int ans = 0;
    
    for (int i = 1; i <= M-1; ++i) {
        int curT = T-Ex*(S[i]-1), tmp = S[i];
        if (curT < 0) continue;
        
        int l = 0, r = S[i+1]-tmp;
        while(r-l > 1) {
            int mid = (l+r)>>1;
            if (curT-mid*L >= 0) l = mid;
            else r = mid;
        }
        ans += l+1;
        //cout<<S[i]<<' '<<S[i]+l<<endl;
        
        tmp = S[i]+l+1;
        curT -= (l+1)*Sm;
        if (curT < 0 || tmp == S[i+1]) continue;
        l = 0, r = S[i+1]-tmp;
        
        while(r-l > 1) {
            int mid = (l+r)>>1;
            if (curT-mid*L >= 0) l = mid;
            else r = mid;
        }
        
        pq.push({l+1,{i,tmp+l+1}});
    }
    
    while(K && !pq.empty()) {
        //cout<<"pass"<<endl;
        pair<int,pii> cur = pq.top();
        pq.pop();
        ans += cur.first;
        K--;
        
        int tmp = cur.second.second;
        int curT = T-Ex*(S[cur.second.first]-1)-Sm*(tmp-S[cur.second.first]);
        if (curT < 0 || tmp == S[cur.second.first+1]) continue;
        
        int l = 0, r = S[cur.second.first+1]-tmp;
        
        while(r-l > 1) {
            int mid = (l+r)>>1;
            if (curT-mid*L >= 0) l = mid;
            else r = mid;
        }
        
        pq.push({l+1,{cur.second.first,tmp+l+1}});
    }
    
    if ((N-1)*Ex <= T) ans++;
    cout<<ans-1<<'\n';
    return 0;
}
