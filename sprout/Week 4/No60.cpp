#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int m, s, t;
//t_s = stop
//t_m = move

int time(int t_s) {
    int t_m = t-t_s;
    m += d*t_s;
    
}

int distance(int t_s) {

}

int main() {
    cin>>a>>b>>c>>d;
    cin>>m>>s>>t;
    int shortest = 1e9;
    int farthest = 0;
    for (int i = 0; i < t; ++i) {// i = stop time
        int y = time(i);
        if (y) {
            if (y < shortest) shortest = y;
        } else {
            int x = distance(i);
            if (x > farthest) farthest = x;
        }
    }
}