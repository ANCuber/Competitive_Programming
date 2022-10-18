#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, b;
    while(cin>>n>>b) {
        if (b) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n-i-1 ;++j) {
                    cout<<' ';
                }
                for (int j = 0; j < 2*i+1; ++j) {
                    cout<<'*';
                }
                cout<<endl;
            }
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n-i-1 ;++j) {
                    cout<<' ';
                }
                for (int j = 0; j < 2*i+1; ++j) {
                    if(j == 0 || j == 2*i || i == 0 || i == n-1)cout<<'*';
                    else cout<<' ';
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
