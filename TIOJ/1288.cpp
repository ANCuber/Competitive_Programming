#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<vector<int> > a(2,vector<int>(n+5,0));
    int x;
    cin>>x;
    a[1][0] = x;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cin>>x;
            if (j == 0) {
                a[i%2][j] = a[(i+1)%2][j]+x;
            } else if (j == i-1) {
                a[i%2][j] = a[(i+1)%2][j-1]+x;
            } else {
                a[i%2][j] = max(a[(i+1)%2][j],a[(i+1)%2][j-1])+x;
            }
        }
    }
    cout<<*max_element(a[n%2].begin(),a[n%2].end())<<endl;
    return 0;
}
