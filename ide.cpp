#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int R, C;
    while(cin>>R>>C) {
        vector<vector<int> > arr(R+2,vector<int>(C+2));
        vector<vector<char> > ans(R+2,vector<int>(C+2));
        for (int i = 1; i <= R; ++i) {
            for (int j = 1 ;j <= C; ++j) {
                cin>>arr[i][j];
            }
        }
    }
     
    return 0;
}
