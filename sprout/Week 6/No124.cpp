#include <bits/stdc++.h>
using namespace std;

int delta_x[4] = {1,1,0,0};
int delta_y[4] = {1,0,1,0};
int black_x[4] = {0,0,-1,-1};
int black_y[4] = {0,-1,0,-1};

void Report(int x1, int y1, int x2, int y2, int x3, int y3) {
    cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<x3<<' '<<y3<<endl;
} 

void distribute (int n, int x, int y, int dx, int dy) {
    if (n == 2) {
        int px[3], py[3];
        int id = 0;
        for (int i = 0; i < 4; ++i) {
            if (dx+delta_x[i] == x && dy+delta_y[i] == y) continue;
            px[id] = dx+delta_x[i];
            py[id] = dy+delta_y[i];
            id++;
        }
        Report(px[0],py[0],px[1],py[1],px[2],py[2]);
    } else {
        int half = n/2;
        int cen_x[3];
        int cen_y[3];
        int id = 0;
        for (int i = 0; i < 4; ++i) {
            int a = dx+half*delta_x[i];
            int b = dy+half*delta_y[i];
            if ((x-dx)/half == delta_x[i] && (y-dy)/half == delta_y[i]) {
                distribute(half,x,y,a,b);
            } else {
                int s = dx+half+black_x[i];
                int t = dy+half+black_y[i];
                cen_x[id] = s;
                cen_y[id] = t;
                id++;
                distribute(half,s,t,a,b);
            }
        }
        Report(cen_x[0],cen_y[0],cen_x[1],cen_y[1],cen_x[2],cen_y[2]);
    }
}

void solve (int n, int x, int y) {
    distribute(n,x,y,1,1);
}

int main() {
    int n; cin>>n;
    int x, y;
    cin>>x>>y;
    solve(n,x,y);
    return 0;
} 