#include <bits/stdc++.h>
using  namespace std;

//W 000 0
//Y 001 1
//B 010 2
//R 100 4
//O 101 5
//P 110 6
//G 011 3
//D 111 7

int dx[8] = {+1,-1,0,0,+1,-1,+1,-1};
int dy[8] = {0,0,+1,-1,+1,+1,-1,-1};

struct position{
    int x, y;
    int color;
};

int Color(char x) {
    switch(x) {
        case 'Y':
            return 1;
        case 'B':
            return 2;
        case 'R':
            return 4;
        case 'O':
            return 5;
        case 'P':
            return 6;
        case 'G':
            return 3;
        case 'D':
            return 7;
    }
}

int aorb(int a, int b) {
    return a|b;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        queue <position> q;
        vector <vector <int> > graph(n+2,vector <int> (n+2,0) );
        for (int i = 0; i < n+2; ++i) {
            graph[0][i] = 7;
            graph[n+1][i] = 7;
            graph[i][0] = 7;
            graph[i][n+1] = 7;
        }
        for (int i = 0; i < 3; ++i) {
            char c; cin>>c;
            int x, y; cin>>x>>y;
            x++; y++;
            position a;
            a.x = x; a.y = y;
            if (c == 'Y') {
                graph[x][y] = 1;
                a.color = 1;
            } else if (c == 'B') {
                graph[x][y] = 2;
                a.color = 2;
            } else {
                graph[x][y] = 4;
                a.color = 4;
            }
            q.push(a);
        }
        char xc; cin>>xc;
        vector <int> echolen(n+5,0);
        echolen[1] = 3;
        int ctrl = 1;
        int maxans = -1;

        vector <int> dark(n+5,0);

        vector <int> ans(n+5,0);
        if (xc == 'Y' || xc == 'B' || xc == 'R') ans[0] = 1;
        int aim = Color(xc);
        while (!q.empty()) {
            ans[ctrl] += ans[ctrl-1];
            while (echolen[ctrl]--) {
                position center = q.front();
                q.pop();
                for (int i = 0; i < 8; ++i) {
                    int ori = graph[center.x+dx[i]][center.y+dy[i]];
                    int now = center.color;
                    if ((ori|now) == ori) continue;

                    if (ori == aim) ans[ctrl]--;
                    if (ori == 7) dark[ctrl]--;
                    graph[center.x+dx[i]][center.y+dy[i]] |= now;
                    if (graph[center.x+dx[i]][center.y+dy[i]] == aim) ans[ctrl]++;
                    if (graph[center.x+dx[i]][center.y+dy[i]] == 7) dark[ctrl]++;

                    position newin;
                    newin.x = center.x+dx[i];
                    newin.y = center.y+dy[i];
                    newin.color = center.color;
                    q.push(newin);
                    echolen[ctrl+1]++;
                }
            }
            if (maxans < ans[ctrl]) maxans = ans[ctrl];
            if (dark[ctrl] >= n*n) break;
            ctrl++;
        }
        cout<<maxans<<'\n';
    }
    return 0;
}