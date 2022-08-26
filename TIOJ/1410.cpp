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
    int n;
    while(cin>>n) {
        int s[n+5], f[n+5];
        for (int i = 0; i < n; ++i) cin>>s[i]>>f[i];
        sort(s,s+n), sort(f,f+n);
        int mx = f[n-1], mn = s[0];
        int sp = 0, fp = 0, cnt = 0, ans = 0;
        for (int i = mn; i <= mx; ++i) {
            while(sp < n && s[sp] == i) {sp++; cnt++;}; 
            ans = max(cnt,ans);
            while(fp < n && f[fp] == i) {fp++; cnt--;}
        }
        cout<<ans<<endl;
    }
    return 0;
}
