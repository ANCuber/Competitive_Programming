#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
//#define endl '\n'

int dx[9] = {0,0,0,1,-1,1,1,-1,-1};
int dy[9] = {0,1,-1,0,0,1,-1,-1,1};
int a, b, c;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>a>>b>>c;
    vector<vector<int> > g(a+2,vector<int>(b+2,0));
    int x, y, cnt = 0;
    while(c--) {
        cin>>x>>y;
        
    }
    cout<<cnt<<endl;
    return 0;
}
