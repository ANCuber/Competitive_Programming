#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string x;
    while(cin>>x) {
        int ctrl = 1;
        for (int i = 0; i < x.size()>>1; ++i) {
            if (x[i] != x[x.size()-i-1]) ctrl = 0;
        }
        if (ctrl) cout<<"palindrome"<<endl;
        else cout<<"not palindrome"<<endl;
    }
    return 0;
}
