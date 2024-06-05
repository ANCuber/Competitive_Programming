#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int N, mx = 0;
int a[6][5] = {
    {1,2,7,8,17},
    {3,0,4,11,12},
    {6,5,0,0,0},
    {9,10,0,18,16},
    {14,13,19,20,15}
};



signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    dfs(0,1);
    cout<<mx<<endl;
    return 0;
}
