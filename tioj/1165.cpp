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
    int a[3];
    while(cin>>a[0]>>a[1]>>a[2]) {
        sort(a,a+3);
        if (a[0]+a[1] == a[2]) cout<<"Good Pair"<<endl;
        else cout<<"Not Good Pair"<<endl;
    }
    return 0;
}
