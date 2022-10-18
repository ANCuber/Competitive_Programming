#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int w, a; 
    int mx=-1, cmx=-1;
    cin>>w;        
    for (int i = 0; i < w; ++i) {
        cmx = -1;
        for (int j = 0; j < w; ++j) {
            cin>>a;
            if (!i || a>mx) cout<<'('<<j<<','<<i<<')'<<endl;
            cmx = max(cmx,a);
        }
        mx = cmx;
    }
    return 0;
}
