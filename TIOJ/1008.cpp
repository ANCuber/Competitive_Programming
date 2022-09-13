#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int mg[5];
int ans = 0;
int n, t; 

int encoder() {

}

int decoder() {

}

void dfs() {

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>mg[i];
    }
    cin>>t;
    bool brk = 0;
    for (int i = 1; i <= n; ++i) if (mg[i]>=t) brk = 1;
    if (!brk) {
        cout<<-1<<endl;
        return 0;
    }

}