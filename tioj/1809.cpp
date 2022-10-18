#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    set < pii > st;
    int a, b;
    while(m--) {
        cin>>a>>b;
        st.insert({min(a,b),max(a,b)});
    }
    while(q--) {
        cin>>a>>b;
        if (st.find({min(a,b),max(a,b)}) != st.end()) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
