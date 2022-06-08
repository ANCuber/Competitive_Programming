#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll ans = 0;
vector <pair<int,int> > p;
vector <int> bl;

void solve(int l, int r) {
    if (l == r) return;
    int mid = (l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);
    vector <pair<int,int> > v;
    int p1 = l, p2 = mid+1;
    while(p1<=mid && p2<=r) {
        if (p[p1].first < p[p2].first) {
            v.push_back(p[p1++]);
        } else {
            ans += (p1-l)*p[p2].second;
            v.push_back(p[p2++]);
        }
    }
    while(p1<=mid) {
        v.push_back(p[p1++]);
    }
    while(p2<=r) {
        ans += (p1-l)*p[p2].second;
        v.push_back(p[p2++]);
    }
    for (int i = 0;i < v.size(); ++i) {
        p[l+i] = v[i];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    p.resize((n<<1)+1);
    bl.assign(n+1,0);
    for (int i = 1; i <= (n<<1); ++i) {
        int a; cin>>a;
        if (!bl[a]) {
            p[i] = {a,-1};
            bl[a]++;
        } else {
            p[i] = {a,1};
        }
    }
    solve(1,n<<1);
    cout<<ans<<endl;
    return 0;
}