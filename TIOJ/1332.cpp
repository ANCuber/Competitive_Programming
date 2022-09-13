#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> fa(n+1,0), id(n+1), a(n+1,0);
    stack<int,vector<int> > stk;
    stk.push(0);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        id[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int pp = 0;
        while(stk.top() > id[i]) {
            pp = stk.top();
            stk.pop();
        }
        fa[i] = a[stk.top()];
        fa[a[pp]] = i;
        stk.push(id[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout<<fa[i]<<endl;
    }
    
    return 0;
}
