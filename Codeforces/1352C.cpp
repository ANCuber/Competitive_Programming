#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int len(int x) {
    int cnt = 0;
    while(x) {
        if (x == 10){
            cnt += 2;
            break;
        }
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;       
    while(t--) {
        int n; cin>>n;
        int cnt = 0;
        vector<int> a(n),b(n);
        for (auto& i : a) cin>>i;
        for (auto& i : b) cin>>i;
        sort(a.begin(),a.end()); sort(b.begin(),b.end());
        
    }

    return 0;
}
