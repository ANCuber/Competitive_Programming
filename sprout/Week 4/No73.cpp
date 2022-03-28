#include <bits/stdc++.h>
using namespace std;

vector <int> c;
int n, m;

bool judge(int x) {
    int curper = 0;
    int mcount = 1;
    for (int i = 0; i < n; ++i) {
        curper += c[i];
        if (curper > x) {
            curper = 0;
            mcount++;
            i--;
        }
        if (mcount > m) break;
    }
    //cout<<mcount;
    if (mcount > m) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        c.resize(n);
        for (int i = 0; i < n; ++i) {
            cin>>c[i];
        }
        int high = 1e9;
        int low = 1;
        int guess = (high+low)/2;
        /* for (int i = 1; i < 11; ++i) {
            cout<<judge(i)<<' ';
        }
        cout<<'\n'; */
        while(high > low) {
            if (!judge(guess)) {
                low = guess+1;
            } else {
                high = guess;
            }
            guess = (high+low)/2;
        }
        cout<<guess<<'\n';
    }
    return 0;
}