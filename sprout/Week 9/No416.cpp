#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define endl '\n'

int adder(int a, int b) {
    a %= mod;
    b %= mod;
    if ((a+b)%mod < 0) return (a+b)%mod+mod;
    return (a+b)%mod;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b, k;
    cin>>n>>a>>b>>k;
    vector <int> curway(n+1,0);
    curway[a] = 1;
    int presum[n+1][2] = {{0}};
    
    for (int i = 0; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i > 0) {
                if (j < b) {
                    curway[j] = (presum[j+(b-j-1)/2][(i+1)%2]%mod-curway[j])%mod;
                }
                if (j > b) {
                    curway[j] = (adder(presum[n][(i+1)%2],-presum[j+(b-j-1)/2][(i+1)%2])-curway[j])%mod;
                }
                if (j == b) curway[j] = 0;
            }
            presum[j][i%2] = adder(curway[j],presum[j-1][i%2]);
        }
    }

    cout<<presum[n][k%2]<<endl;
    return 0;
}
