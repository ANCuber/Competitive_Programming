#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define pii pair<long long,long long>
#define puu pair<unsigned long long,unsigned long long>
#define p_q priority_queue
#define endl '\n'
#define pb emplace_back

inline pii M(pii a, pii b) {
    return {a.first-b.first,a.second-b.second};
}

signed main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int n; cin>>n;    
    int n, N;
    scanf("%d",&n);
    
    vector<pii> d(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld",&d[i].first,&d[i].second);
    }
    
    bitset<10005> used, vis;
    vis.reset();
    vis[0] = 1;
    for (int i = 1; i < n; i += ((n > 5000)?(2):(1))) {
        
        if (vis[i]) continue;
        used.reset();
        used[0] = 1;
        pii cur = M(d[0],d[i]);
        for (int j = 1; j < n; ++j) {
            pii tmp = M(d[0],d[j]);
            if (cur.first*tmp.second == tmp.first*cur.second) {
                vis[j] = used[j] = 1;
            }
        }
        vector<pii> arr;
        for (int j = 1; j < n; ++j) {
            if (used[j]) continue;
            arr.pb(d[j]);
        }
        if (arr.size() < 5) {
            printf("possible\n");
            return 0;
        }
        
        pii ano;
        int flg = 0;
        
        for (int j = 0; j < 5; ++j) {
            for (int k = j+1; k < 5; ++k) {
                for (int l = k+1; l < 5; ++l) {
                    pii A = M(arr[j],arr[k]), B = M(arr[j],arr[l]);
                    if (A.first*B.second == B.first*A.second) {
                        ano = A;
                        flg = 1;
                    }
                }
            }
        }
        
        if (!flg) continue;
        
        vector<pii> lst;
        for (int j = 1; j < arr.size(); ++j) {
            pii nw = M(arr[0],arr[j]);
            if (nw.first*ano.second != ano.first*nw.second) lst.pb(arr[j]);
        }
        
        if (lst.size() <= 2) {
            printf("possible\n");
            return 0;
        }
        
        flg = 0;
        ano = M(lst[0],lst[1]);
        for (int j = 2; j < lst.size(); ++j) {
            pii nw = M(lst[0],lst[j]);
            if (nw.first*ano.second != ano.first*nw.second) {
                flg = 1;
            }
        }
        if (!flg) {
            printf("possible\n");
            return 0;
        }
    }
    printf("impossible\n");
    return 0;
}
