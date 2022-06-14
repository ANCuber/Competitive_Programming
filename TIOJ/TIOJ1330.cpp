#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    int n; cin>>n;
    while(n--){
        int t; cin>>t;
        if (t&1) {
            cout<<1<<endl;
        } else {
            cout<<0<<endl;
        }
    }
    return 0;
}