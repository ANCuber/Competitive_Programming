#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string output[] = {"No","Yes"};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector <int> v(n+5);//$
        vector <int> k(n+5);//amount
        for (int i = 1; i <= n; ++i) {
            cin>>v[i]>>k[i];
        }
        bool dp[2][m+1] = {0};
        fill(dp[0],dp[0]+m+1,0);
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int arr[v[i]];
            fill(arr,arr+v[i],-1);
            for (int j = 0; j <= m; ++j) {
                if (dp[(i+1)%2][j]) {
                    dp[i%2][j] = true;
                    arr[j%v[i]] = j;
                } else {
                    if (arr[j%v[i]] < 0 || arr[j%v[i]] < j-v[i]*k[i]) {
                        dp[i%2][j] = false;
                    } else {
                        dp[i%2][j] = true;
                    }
                }
            }
        }
        cout<<output[dp[n%2][m]]<<endl;
    }
    return 0;
}

/* 
2
2 11
2 2
3 3
2 1
2 3
3 2 
*/

//TLE method(original)
//O(NMK)
/*  for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            bool ans = false;
            for (int h = 0; h <= k[i]; ++h) {
                if (v[i]*h > j) break;
                ans = ans|dp[(i+1)%2][j-h*v[i]];
            }
            dp[i%2][j] = ans;
        }
    } */