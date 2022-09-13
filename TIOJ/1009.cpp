#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define endl '\n'
int x[3] = {3600,60,1};

int main() {
    string a , b;
    cin>>a>>b;
    int at = 0, bt = 0;
    for (int i = 0; i < 8; i+=3) {
        at += ((a[i]-'0')*10+(a[i+1]-'0'))*x[i/3];
        bt += ((b[i]-'0')*10+(b[i+1]-'0'))*x[i/3];
    }
    //cout<<at<<' '<<bt<<endl;
    if (at > bt) bt += 3600*24;
    int ans = bt-at;
    for (int i = 0; i < 3; ++i) {
        int s = ans/x[i];
        if (s < 10) cout<<0<<s;
        else cout<<s;
        if (i != 2)cout<<':';
        ans %= x[i];
    }
    return 0;
}