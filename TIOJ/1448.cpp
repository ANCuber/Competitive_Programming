#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int n, k;
vector<int> type;

bool judge(int d, int x, int y) {
    if (x > n || y > n) return true;
    if (d == 2 && x == y) return true;
    if (d == 1) {
        if (type[x] == type[y] && type[x] != 0) return false;
        if (type[x] == type[y]) {
            
        }
        else if (type[x] == 0 || type[y] == 0) {
            
        }
        return true;
    } else {
        if (type[x] == type[y] && type[x] != 0) return true;

    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    type.resize(n+1,0);
    int d, x, y;
    int ans = 0;
    while(k--) {
        cin>>d>>x>>y;
        ans += judge(d,x,y);
    }
    return 0;
}
