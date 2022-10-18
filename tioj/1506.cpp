#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double a1, a2, b1, b2;
    cin>>a1>>a2>>b1>>b2;
    cout<<setprecision(2)<<fixed;
    if (a1 == 0 || a2 == 0) {
        if (a1) {
            cout<<(b2-b1)/a1<<endl<<b2<<endl;
        } else {
            cout<<(b1-b2)/a2<<endl<<b1<<endl;
        }
    } else {
        cout<<(b2-b1)/(a1-a2)<<endl<<((a2*b1/a1)-b2)/((a2/a1)-1)<<endl;
    }
    return 0;
}
