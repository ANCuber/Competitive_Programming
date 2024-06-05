#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int> 
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

int N, M;
int A[2][500005];

#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)

struct SegmentTree {
    int L;
    vector<int> v, aTag, sz;
 
    SegmentTree(int N): L(N), v(L << 1), aTag(L << 1), sz(L << 1, 1) {
 
        for (int i = N - 1; i > 0; i--) {
            v[i] = v[lc(i)] + v[rc(i)];
            sz[i] = sz[lc(i)] + sz[rc(i)];
        }
    }
 
    void update(int i, int d) {
        v[i] += d * sz[i];
        aTag[i] += d;
    }
 
    void pull(int i) {
        for (int h = __lg(L); h >= 0; h--) {
            int p = i >> h + 1;
            if (aTag[p]) {
                update(lc(p), aTag[p]);
                update(rc(p), aTag[p]);
                aTag[p] = 0;
            }
        }
    }
 
    void push(int i) {
        i >>= 1;
        for (int h = 1; i; i >>= 1, h++) {
            v[i] = v[lc(i)] + v[rc(i)] + aTag[i] * sz[i];
        }
    }
 
    void mdf(int l, int r, int d) {
        int ll = l + L, rr = r + L - 1;
        pull(ll), pull(rr);
        for (l += L, r += L; l < r; l >>= 1, r >>= 1) {
            if (l & 1) update(l++, d);
            if (r & 1) update(--r, d);
        }
        push(ll), push(rr);
    }
 
    int query(int l, int r) {
        int ans = 1e9;
        pull(l + L), pull(r + L - 1);
        for (l += L, r += L; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, v[l++]);
            if (r & 1) ans = min(ans, v[--r]);
        }
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>N>>M;
    vector<SegmentTree> seg(2, N);
    for (int i = 0; i < N; ++i) seg[1].mdf(i,i+1,-(i+1));
    for (int i = 0; i < N; ++i) seg[0].mdf(i,i+1,-(N-(i+1)+1));
    vector<pii> pz(M+5); 
    int aw = 0;
    for (int i = 1; i <= M; ++i) {
        cin>>pz[i].first>>pz[i].second;
        if (pz[i].first==1 && pz[i].second==N) aw++;
        else if (pz[i].first==1) {
            seg[0].mdf(0,pz[i].second,1);
        } else {
            seg[1].mdf(pz[i].first-1,N,1);
        }
    }
    int Q; cin>>Q;
    int cmd, l, r, x, s, t, L, R, M, LL, RR, C;
    while(Q--) {
        int cmd; cin>>cmd;
        if (cmd == 1) {
            cin>>x>>s>>t;
            if (pz[x].first==1 && pz[x].second==N) aw--;
            else if (pz[x].first==1) {
                seg[0].mdf(0,pz[x].second,-1);
            } else {
                seg[1].mdf(pz[x].first-1,N,-1);
            }
            pz[x] = {s,t};
            if (pz[x].first==1 && pz[x].second==N) aw++;
            else if (pz[x].first==1) {
                seg[0].mdf(0,pz[x].second,1);
            } else {
                seg[1].mdf(pz[x].first-1,N,1);
            }
        } else {
            cin>>l>>r;
            L = l-1, R = r+1;
            M = (L+R)>>1;
            LL = (N-l+1), RR = (r), C;
            while(R-L > 1) {
                C = M-l+1;
                if (seg[0].query(l-1,M)+(LL-C) >= 0) L = M;
                else R = M;
                M = (L+R)>>1;
            }
            LL = L;
            L = l-1, R = r+1;
            M = (L+R)>>1;
            while(R-L > 1) {
                C = r-M+1;
                if (seg[1].query(M-1,r)+(RR-C) >= 0) R = M;
                else L = M;
                M = (L+R)>>1;
            }
            RR = R;
            if (LL+aw >= RR-1) {
                cout<<"Yes\n";
            } else {
                cout<<"No\n";
            }
        }
    }
    return 0;
}
