#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int solve(vector<int> &a, int l, int r) {
    if (l == r) return 0;
    if (r-l == 1) {
        if (a[l] <= a[r]) return 0;
        swap(a[l],a[r]);
        return 1;
    }
    int mid = (l+r)>>1;
    int ret = solve(a,l,mid)+solve(a,mid+1,r);
    vector <int> tmp;
    int p1 = l, p2 = mid+1;
    while(p1<=mid && p2<=r) {
        if (a[p1] > a[p2]) {
            ret += (mid-p1+1);
            tmp.push_back(a[p2++]);
        } else {
            tmp.push_back(a[p1++]);
        }
    }
    while(p1<=mid) {
        tmp.push_back(a[p1++]);
    }
    while(p2<=r) {
        tmp.push_back(a[p2++]);
    }
    for (int i = 0; i < r-l+1; ++i) {
        a[l+i] = tmp[i];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin>>a[i];
        cout<<solve(a,1,n)<<endl;
    }
    return 0;
}
