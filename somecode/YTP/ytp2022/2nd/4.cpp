#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

struct Square {
    ll x[2];
    ll y[2];
};

struct Circle {
    ll x, y, r;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int audience, stage;
    cin >> audience >> stage;

    vector<Square> square(audience);
    for (auto& n: square) cin >> n.x[0] >> n.y[0] >> n.x[1] >> n.y[1];

    vector<Circle> circle(stage);
    for (auto& n: circle) cin >> n.x >> n.y >> n.r;

    for (auto& o: circle) {
        int current = 0;
        for (int k = 0; k < audience; k++) {
            bool flag = 0;
            for (int i = 0; i < 2; i++) {
                if (flag) break;
                for (int j = 0; j < 2; j++) {
                    if (flag) break;
                    ll dx = o.x - square[k].x[i];
                    ll dy = o.y - square[k].y[j];
                    if (dx * dx + dy * dy <= o.r * o.r) {
                        current++;
                    }
                }
            }

            if (flag) continue;
            if (square[k].x[0] <= o.x && o.x <= square[k].x[1]) {
                if (abs(o.y - square[k].y[0]) <= o.r) {
                    current++;
                    continue;
                } else if (abs(o.y - square[k].y[1]) <= o.r) {
                    current++;
                    continue;
                }
            } 
            if (square[k].y[0] <= o.y && o.y <= square[k].y[1]) {
                if (abs(o.x - square[k].x[0]) <= o.r) {
                    current++;
                    continue;
                } else if (abs(o.x - square[k].x[1]) <= o.r) {
                    current++;
                    continue;
                }
            }
 
        }
        cout << current << '\n';
    }
}
