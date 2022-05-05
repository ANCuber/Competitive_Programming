#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int number[8] = {100000,10000,0,1000,100,0,10,1};

int main() {
    string a , b;
    cin>>a>>b;
    int at = 0, bt = 0;
    int j = 100000;
    for (int i = 0; i < 8; ++i) {
        if (i == 2 || i == 5) continue;
        at += (a[i]-'0')*j;
        bt += (b[i]-'0')*j;
        j /= 10;
    }
    if (at > bt) bt += 240000;
    int ans = bt-at;
    for (int i = 0; i < 8; ++i) {
        if (i == 2 || i == 5) cout<<':';
        else cout<<(ans/number[i])%10;
    }
    cout<<endl;
    return 0;
}