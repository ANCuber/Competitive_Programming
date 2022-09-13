#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

const int mxn = 50000;

int mu[mxn+5] = {0};
int prime[mxn+5] = {0};
int np[mxn+5] = {0};
/*
Mobius Function:
mu[n] = 1, n = 1
mu[n] = 0, n = c*k^2
mu[n] = (-1)^k, k = number of prime factor of a spuare-free positive int(n)
*/

void getmu() {
    mu[1] = 1;
    for (int i = 2; i <= mxn; ++i) {
        if (!np[i]) {
            prime[++prime[0]] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= prime[0] && prime[j]*i <= mxn; ++j) {
            np[i*prime[j]] = 1;
            if (!(i%prime[j])) {
                mu[i*prime[j]] = 0;
                break;
            }
            mu[i*prime[j]] = -mu[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    getmu();
    int a, b, d;
    while(cin>>a>>b>>d && a+b+d > 0) {
        int ans = 0;
        for (int i = 1; i <= min(a/d,b/d); ++i) {
            ans += mu[i]*(a/d/i)*(b/d/i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
