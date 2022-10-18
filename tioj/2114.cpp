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
    int t; cin>>t;
    ll n, m, k;    
    while(t--) {
        cin>>n>>m>>k;
        if ((--n)^(--m)^(--k)) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    return 0;
}
