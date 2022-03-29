#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int m, s, t;

int distance(int tlimit) {
    int max_d = 0;
    for (int i = 0; i <= tlimit; i++) {
        int t_m = tlimit-i;
        int gas = m+d*i;
        int canuseb = min(gas/c,t_m);
        int dx = canuseb*b + a*(t_m-canuseb);
        max_d = max(max_d,dx);
    }
    return max_d;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>a>>b>>c>>d;
    cin>>m>>s>>t;
    int high = t+1;
    int low = 1;
    int guess = (high+low)/2;
    int c = 0;
    while(high > low) {
        int x = distance(guess);
        if (x >= s) {
            high = guess;
            c = 1;
        } else {
            low = guess+1;
        }
        guess = (high+low)/2;
    }
    if (guess<=t) {
        cout<<"Yes\n";
        cout<<guess<<'\n';
    } else {
        cout<<"No\n";
        cout<<distance(t)<<'\n';
    }
    return 0;
}