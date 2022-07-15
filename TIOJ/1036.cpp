#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

bitset <10000005> p;
vector <int> a(10000005,0);

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m;
    p.set();
    for (int i = 2; i <= 3163; ++i) {
        if (p[i]) {
            for (int j = i*i; j <= 10000000; j += i) {
                p[j] = 0;
            }
        }
    }
    p[1] = 0;
    for (int i = 1; i <= 10000000; ++i) {
        a[i] = a[i-1];
        if (p[i]) a[i]++;
    }

    while(m--) {
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}
