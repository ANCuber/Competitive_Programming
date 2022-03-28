#include <bits/stdc++.h>
using namespace std;

int r, c, m;

void rotate(vector <vector<int> > &B, vector <vector<int> > A) {
    B.clear();
    for (int i = 0; i < c; ++i) {
        vector <int> x;
        B.push_back(x);
        for (int j = 0; j < r; j++) {
            
        }
    }
}

void revolve(vector <vector<int> > &B) {
    for (int i = 0; i < r/2; ++i) {
        for (int j = 0; j < c; ++j) {
            B[i][j] = B[r-i-1][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(true){
        cin>>r>>c>>m;
        if (cin.fail()) break;
        vector <vector<int> > B(r, vector<int> (c,0));
        vector <int> move(m);
        for (int i = 0; i < r; ++r) {
            for (int j = 0; j < c; ++j) {
                cin>>B[i][j];
            }
        }
        for (int i = m-1; i >= 0; --i) {
            cin>>move[i];
        }
        for (int i = 0; i < m; ++i) {
            if (!move[i]) {
                rotate(B,B);
            } else {
                revolve(B);
            }
        }
        
    }
    return 0;
}