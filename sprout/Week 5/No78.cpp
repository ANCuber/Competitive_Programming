#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int gifts[6];
        long long ans = 0;
        for (int i = 0; i < 6; ++i) {
            cin>>gifts[i];
            if (i == 0 || i == 1 || i == 2 || i == 5) {
                int x = 36/((i+1)*(i+1));
                ans += (long long)(gifts[i]/x);
                gifts[i] = gifts[i]%x;//deal with 6x6 and other gifts
            }
        }
        // deal with 5x5
        int for_1 = 11*gifts[4];//1x1 square, only for 1x1
        ans += (long long)gifts[4];
        gifts[4] = 0;
        if (gifts[0] >= for_1) {
            gifts[0] -= for_1;
            for_1 = 0;
        } else {
            for_1 -= gifts[0];
            gifts[0] = 0;
        }
        //deal with 4x4
        int for_2 = 5*gifts[3];//2x2 square
        ans += (long long)gifts[3];
        gifts[3] = 0;
        if (gifts[1] >= for_2) {
            gifts[1] -= for_2;
            for_2 = 0;
        } else {
            for_2 -= gifts[1];
            gifts[1] = 0;
            for_1 += for_2*4;
        }
        int extra_3;
        if(gifts[2]) {//deal with 3x3
            ans++;
            extra_3 = 4-gifts[2];
            gifts[2] = 0;
        }
        if(gifts[1]) {
            if (extra_3 == 1) {
                gifts[1]--;
                for_1 += 5;
            } else if (extra_3 == 2) {
                if (gifts[1] <= 3) {
                    gifts[1] = 0;
                    for_1 += 6;
                } else {
                    for_1 += 6;
                    gifts[1] -= 3;
                }
            } else if (extra_3 == 3) {
                if (gifts[1] <= 5) {
                    gifts[1] = 0;
                    for_1 += 7;
                } else {
                    for_1 += 7;
                    gifts[1] -= 5;
                }
            }
        }
        if (gifts[1]) {
            ans++;
            for_1 += (36-4*gifts[1]);
        }
        gifts[0] -= for_1;
        if (gifts[0] >= 1) {
            ans++;
        }
        cout<<ans<<'\n';
    }
}