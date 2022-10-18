#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        if (n%3 == 0) {
            if (n%9 == 0) {
                if (n%27 == 0) {
                    cout<<"sad"<<endl;
                } else {
                    cout<<"happy"<<endl;
                }
            } else {
                cout<<"sad"<<endl;
            }
        } else {
            cout<<"happy"<<endl;
        }
    }
    return 0;
}
