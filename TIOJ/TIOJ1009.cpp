#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int x[3] = {3600,60,1};

int main() {
    string a , b;
    cin>>a>>b;
    int at = 0, bt = 0;
    for (int i = 0; i < 8; i+=3) {
        at += ((a[i]-'0')*10+(a[i+1]-'0'))*x[i/3];
        bt += ((b[i]-'0')*10+(a[i+1]-'0'))*x[i/3];
    }
    if (at > bt) bt += 3600*24;
    int ans = bt-at;
    for (int i = 0; i < 3; ++i) {
        
    }
    return 0;
}