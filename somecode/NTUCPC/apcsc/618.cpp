#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct Info{
    string name, number, group;
    int sc, a, b, c, d, si;
    bool operator<(Info y) {
        if (sc != y.sc) return sc < y.sc;
        if (si != y.si) return si < y.si;
        return name < y.name;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<Info> s(n);
    for (auto &[i,j,k,l,a,b,c,d,h] : s) {
        cin>>i>>j>>k>>l>>a>>b>>c>>d;
        h = a+b+c+d;
    }
    sort(s.begin(),s.end());
    int q; cin>>q;
    while(q--) {
        int x; cin>>x;
        cout<<"Student "<<x<<'\n';
        cout<<"name = "<<s[--x].name<<'\n';
        cout<<"number = "<<s[x].number<<'\n';
        cout<<"group = "<<s[x].group<<'\n';
        cout<<"score_concept = "<<s[x].sc<<'\n';
        cout<<"score_implement = "<<s[x].a<<' '<<s[x].b<<' '<<s[x].c<<' '<<s[x].d<<'\n';
    }
    return 0;
}
