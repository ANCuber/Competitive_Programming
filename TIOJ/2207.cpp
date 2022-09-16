#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;    
    vector<string> s(k);
    for (auto& i : s) cin>>i;
    if (k == 1) {
        for (auto i : s[0]) cout<<(i=='0');
        cout<<endl;
    } else if (k == 2) {
        int a1 = 0, a2 = 0;
        for (int i = 0; i < n; ++i) {
            
        }
    } else {
        
    }

    return 0;
}
