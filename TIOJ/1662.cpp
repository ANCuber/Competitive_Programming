#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string x;
    int ctrl = 1;
    while(getline(cin,x)) {
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] >= 'a' && x[i] <= 'z') {
                cout<<char(x[i]-32);
                ctrl = 1;
            } else if (x[i] >= 'A' && x[i] <= 'Z') {
                cout<<char(x[i]+32);
                ctrl = 1;
            } else {
                cout<<' ';
                //if (ctrl) cout<<' ';
                ctrl = 0;
            }
        }
        cout<<endl;
    }
    return 0;
}
