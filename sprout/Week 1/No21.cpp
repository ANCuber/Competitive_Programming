#include <bits/stdc++.h>
using namespace std;

struct car{
    int front;
    int back;
};

int main() {
    int n, m; cin>>n>>m;
    car game[n+5];
    game[1].front = -1;
    game[1].back = 2;
    int beginner = 1;
    for (int i = 2; i <= n-1; i++) {
        game[i].front = i-1;
        game[i].back = i+1;
    }
    game[n].front = n-1;
    game[n].back = -2;
    
    for (int l = 1; l <= m; l++) {
        int t, x; cin>>t>>x;
        if (t == 0) {
            if (game[x].front == -1) {
                game[game[x].back].front = -1;
                beginner = game[x].back;
            } else if (game[x].back == -2) {
                game[game[x].front].back = -2;
            } else {
                game[game[x].front].back = game[x].back;
                game[game[x].back].front = game[x].front;
            }
            game[x].front = -1;
            game[x].back = -1;
        } else {
            if (game[x].front == -1) continue;
            int a = game[x].front;
            int b = game[x].back;
            int c = game[game[x].front].front;
            //x
            if (c == -1) {
                game[b].front = a;
                game[x].front = c;
                game[x].back = a;
                game[a].front = x;
                game[a].back = b;
                beginner = x;
            } else if (b == -2) {
                game[game[a].front].back = x;
                game[x].front = c;
                game[x].back = a;
                game[a].front = x;
                game[a].back = b;
            } else {
                game[b].front = a;
                game[game[a].front].back = x;
                game[x].front = c;
                game[x].back = a;
                game[a].front = x;
                game[a].back = b;
            }
        }
    }
    int ptr = beginner;
    cout<<ptr;
    ptr = game[ptr].back;
    while(ptr != -2) {
        cout<<' '<<ptr;
        ptr = game[ptr].back;
    }
    cout<<'\n';
    return 0;
}

//-1.winner, -2.last, 0.dead