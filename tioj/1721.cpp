#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int n;

void solve(vector<int> &h, vector<int> &ans) {
    stack <int,vector<int> > stk;
    for (int i = 0; i < n; ++i) {
        while(!stk.empty() && h[stk.top()] < h[i]) {
            stk.pop();
        }
        if (stk.empty()) {
            ans[i] += i;
        } else {
            ans[i] += (i-stk.top());
        }
        stk.push(i);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n) {
        vector<int> h(n);
        vector<int> ans(n,1);
        for (int i = 0; i < n; ++i) {
            cin>>h[i];
        }
        solve(h,ans);
        reverse(h.begin(),h.end());
        reverse(ans.begin(),ans.end());
        solve(h,ans);
        reverse(ans.begin(),ans.end());
        for (auto i : ans) cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}
