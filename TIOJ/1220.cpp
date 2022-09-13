#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n, m;

int find_boss(int x, vector<int> &boss) {
    if (x == boss[x]) return x;
    return boss[x] = find_boss(boss[x],boss);
}

int main() {
    cin>>n>>m;
    vector<int> boss(n+1,0);
    int a, b;
    while(m--) {
        cin>>a>>b;
        
    }
}
