#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

bool cmp(string a, string b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > b[i]) return 0;
        else if (a[i] < b[i]) return 1;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    string a, b;
    while(t--) {
        cin>>a>>b;
        if (a.size() == b.size()) {
            cout<<cmp(a,b)<<endl;
        } else {
            cout<<(a.size()<=b.size())<<endl;
        }
    }
    return 0;
}
