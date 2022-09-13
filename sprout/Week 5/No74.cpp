#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector <int> height(n+1,0);
        int ans = 1;
        bool ctrl = 0;
        int beginner = -1;
        for (int i = 0; i < n; ++i) {
            cin>>height[i];
        }
        for (int i = 0; i < n-1; ++i) {
            if (height[i] > height[i+1]) {
                beginner = i;
                break;
            }
        }
        if (beginner == -1 || beginner == n-2) {
            cout<<ans<<'\n';
            continue;
        }
        int index = beginner+1;
        while(index <= n-1) {
            if (ctrl) {
                if (height[index] > height[beginner] && height[index] > height[index+1]) {
                    //cout<<"pass";
                    beginner = index;
                    ctrl = 0;
                    ans++;
                }
            } else {
                if (height[index] < height[beginner] && height[index] < height[index+1]) {
                    //cout<<"pass";
                    beginner = index;
                    ctrl = 1;
                    ans++;
                }
            }
            index++;
        }

        cout<<ans<<'\n';
    }
    return 0;
}