#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, r, o = 0; 
    cin>>n>>r;
    vector<int> d(n+5);
    for (int i = 1; i <= n; ++i) {
        cin>>d[i];
        o += d[i];
    }
    int isrt;
    if (o <= r) isrt = r-o;
    else isrt = r-o+10;
    for (int i = 0; i <= n; ++i) {
        
    }
}
