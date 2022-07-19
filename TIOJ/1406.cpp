#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int n;

bool solve(vector<pair<ll,ll> > arr, ll gus) {
    for (int i = 1; i <= n; ++i) {
        arr[i].first -= gus;
    }
    int pre = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i].first < 0) {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n) {
        vector<pair<ll,ll>  > arr(n+1);
        for (int i = 1; i <= n; ++i) {
            cin>>arr[i].first>>arr[i].second;
        }
        arr[0] = arr[1];
        ll l = 0, r = 1e12+1;
        ll gus = (l+r)>>1;
        while(r-l > 1) {
            if (solve(arr,gus)) {
                l = gus;
            } else {
                r = gus;
            }
            gus = (l+r)>>1;
        }
        cout<<gus<<endl;
    }
    return 0;
}
