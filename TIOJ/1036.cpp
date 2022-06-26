#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int MAX = 10000000;

bitset <10000005> nprime(0);

int main() {
    int m; cin>>m;
    for (int i = 2;i <= MAX; ++i) {
        if (!nprime[i]) {
            for (int j = i*i; j <= MAX; j += i) {
                nprime[j] = true;
            }
        }
    } 
    vector <int> pre(MAX+1,0);
    for (int i = 1; i <= MAX; ++i) {
        if (nprime[i]) {
            pre[i]++;
        }
        pre[i] += pre[i-1];
    }
    while(m--) {
        int n; cin>>n;
        cout<<pre[n]<<endl;
    }
    return 0;
}