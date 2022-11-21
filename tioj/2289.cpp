#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, q;

struct my {
    int x, y;
    bool operator<(my b) {
        return x < b.x;
    }
};

signed main() {
    scanf("%d%d",&n,&q);
    vector<my> arr(q);
    for (auto&[x,y] : arr) {
        cin>>x>>y;
    }
    sort(arr.begin(),arr.end());
    
    return 0;
}
