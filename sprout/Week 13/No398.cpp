#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector <unsigned ll> vec;
const long double eps = 1e-10;

void input() {
    string x; cin>>x;
    unsigned ll ret = 0;
    unsigned ll base = 1e8;
    for (int i = 2; i < x.size(); ++i) {
        if (i == 1) continue;
        ret += (x[i]-'0')*base;
        base /= 10;
    }
    vec.push_back(ret);
}

int main() {
    int n; cin>>n;
    int ans = 0;
    for (int i = 0; i < n; ++i) input();
    /* vec.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
    } */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (vec[i] + vec[j] == vec[k]) {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}