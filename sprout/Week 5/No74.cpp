#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector <int> height(n+1,0);
        int ans = 0;
        for (int i = 0; i < n; ++i) cin>>height[i];
        int index = 0;
        while(index < n){
            if (height[index] > height[++index]) {
                ans += 2;
                break;
            }
        }
        int curr = height[index];
        bool ctrl = 0;
        for (int i = index+1; i < n; ++i) {
            if (ctrl) {
                
            } else {
                
            }
        }
        if (!ctrl && ans) ans--;
        cout<<ans<<'\n';
    }
    return 0;
}