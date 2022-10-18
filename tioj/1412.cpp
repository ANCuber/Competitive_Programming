#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int n, m, k;

bool check(vector<int> &a, vector<int> &b, int mid) {
    vector<int> tmp(n);
    for (int i = 0; i < n; ++i) {
        tmp[i] = b[i]*mid;
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (tmp[i]-a[i] < 0) return 0;
        sum += (tmp[i]-a[i]);
    }
    return sum >= k*m;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n) {
        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin>>b[i];
        cin>>k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        cin>>m;
        int l = 0, r = 1e5;
        int mid = l+(r-l)/2;
        while(r-l > 1) {
            if (!check(a,b,mid)) l = mid;
            else r = mid;
            mid = l+(r-l)/2;
        }
        cout<<r<<endl;
    }
    return 0;
}
