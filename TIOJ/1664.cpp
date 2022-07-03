#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

string p[7] = {"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    while(cin>>x) {
        cout<<p[x%7]<<endl;
    }
    return 0;
}
