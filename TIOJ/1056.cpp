#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

string ans[2] = {"POSSIBLE","IMPOSSIBLE"};
int ctrl = 0;
int l[3] = {0};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[3][3];
    char x;
    int O = 0, X = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>x;
            if (x == '.') a[i][j] = 0;
            else if (x == 'O') a[i][j] = 1, O++;
            else if (x == 'X') a[i][j] = 2, X++;
            else ctrl = 1;
        }
    }
    if (O-X > 1 || O-X < 0 || ctrl) {
        cout<<ans[1]<<endl;
        return 0;
    }
    for (int i = 0; i < 3; ++i) {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2]) l[a[i][0]]++;
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i]) l[a[0][i]]++;
    }
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2]) l[a[1][1]]++;
    if (a[0][2] == a[1][1] && a[1][1] == a[2][0]) l[a[1][1]]++;

    
    if (l[1] > 2 || l[2] > 2) cout<<ans[1]<<endl;
    else if (l[1] == 2 && l[2] != 0) cout<<ans[1]<<endl;
    else if (l[2] == 2 && l[1] != 0) cout<<ans[1]<<endl;
    else if (l[1] == 1 && l[2] == 1) cout<<ans[1]<<endl;
    else if (l[1] == 2 && O != X+1) cout<<ans[1]<<endl;
    else if (l[1] == 1 && O != X+1) cout<<ans[1]<<endl;
    else if (l[2] == 1 && X != O) cout<<ans[1]<<endl;
    else cout<<ans[0]<<endl;

    return 0;
}
