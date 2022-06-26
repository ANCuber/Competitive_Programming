#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin>>n>>m;
    int w[n], c[m];
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        cin>>w[i];
    }
    for (int i = 0; i < m; i++) {
        cin>>c[i];
    }
    sort(w, w+n);
    sort(c, c+m);
    int wi = n-1, ci = m-1;
    while(ci>=0 && wi>=0) {
        if (w[wi] <= c[ci]) {
            answer += w[wi];
            wi--;
            ci--;
        } else {
            wi--;
        }
    }
    cout<<answer<<'\n';
    return 0;
}