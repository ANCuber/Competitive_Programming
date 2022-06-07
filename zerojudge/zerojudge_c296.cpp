#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Nd{
    int pre;
    int nex;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    int ans = 0;
    int rem = n-k+1;
    while(k--) {
        ans = (ans+m)%rem;
        rem++;
    }
    cout<<ans+1<<endl;
    return 0;
}