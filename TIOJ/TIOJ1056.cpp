#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int ctrl = 0;
string ans[2] = {"POSSIBLE","IMPOSSIBLE"};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char g[3][3];
    int cir = 0, ow = 0;
    int cro = 0, xw = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>g[i][j];
            if (g[i][j] == 'O') {
                cir++;
            } else if (g[i][j] == 'X') {
                cro++;
            } else if (g[i][j] != '.') {
                ctrl = 1;
            }
        }
    }
    if (cir > cro) ctrl = 1;
    cout<<ans[ctrl]<<endl;
    return 0;
}