#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ull n, k;
    while(cin>>n>>k) {
        ull cnt = 0;
        if (k) {
            for (ull i = 1; i <= n; i*=10) {
                cnt += n/i/10*i;
                if (n/i%10 > k) cnt += i;
                else if (n/i%10 == k) cnt += n%i+1;
            }
        } else { 
            for (ull i = 1; i <= n; i*=10) {
                cnt += (n/i/10-1)*i;
                if (n/i%10 == 0) cnt += n%i+1;
                else cnt += i;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
