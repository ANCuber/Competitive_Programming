#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int di[4] = {0,-1,0,1};
int dj[4] = {-1,0,1,0};

int main() {
    int n, c;
    cin>>n>>c;
    int graph[n][n];
    for (int i = 0;i < n; ++i) {
        for (int j = 0;j < n; ++j) {
            cin>>graph[i][j];
        }
    }
    int times = 1;
    int ctrl = 0;
    int brk = 1;
    pair<int,int> s = make_pair(n/2,n/2);
    cout<<graph[n/2][n/2];
    while(brk < n*n){
        for (int i = 0; i < times; ++i) {
            s.first += di[c];
            s.second += dj[c];
            cout<<graph[s.first][s.second];
            brk++;
            if (brk == n*n) break;
        }
        if (ctrl) {
            times++;
            ctrl = 0;
        }
        else ctrl++;
        c = (c+1)%4;
    }
    cout<<endl;
    return 0;
}