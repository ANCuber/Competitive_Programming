#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int arr[6];
        long long ans = 0;
        int for_1, for_2;
        for (int i = 0; i < 6; ++i) {
            cin>>arr[i];
            if (i == 2 || i == 5) {
                int x = 36/((i+1)*(i+1));
                ans += (long long)(arr[i]/x);
                arr[i] %= x;//deal with 6x6 and 3x3
            } else {
                if (i == 3) {
                    for_2 = 5*(arr[i]);
                    ans += (long long)arr[i];
                } else if(i == 4){
                    for_1 = 11*arr[i];// only for 1x1
                    ans += (long long)arr[i];
                }
            }
        }

        int extra_3 = 0;//extra of 3x3
        if (arr[2] >= 1) {
            extra_3 = 4-arr[2];
            ans++;
        }

        if (extra_3 == 1) {
            if (arr[1]) {
                arr[1]--;
                for_1 += 5;
            } else {
                for_1 += 9;
            }
        } else if (extra_3 == 2) {
            for_1 += 18;
            int u = 3;
            while (arr[1] && u) {
                arr[1]--;
                u--;
                for_1 -= 4;
            }
        } else if (extra_3 == 3) {
            for_1 += 27;
            int u = 5;
            while (arr[1] && u) {
                arr[1]--;
                u--;
                for_1 -= 4;
            }
        }

        while(arr[1] && for_2) {
            arr[1]--;
            for_2--;
        }

        for_1 += 4*for_2;

        if (arr[1] >= 1) {
            ans += (long long)(arr[1]/9);
            arr[1] %= 9;
            if (arr[1]) ans++;
            for_1 += 36-4*arr[1];
        }

        if (arr[0] >= for_1) {
            arr[0] = arr[0]-for_1;
        } else {
            arr[0] = 0;
        }

        if (arr[0] >= 1) {
            ans += (long long)(arr[0]/36);
            arr[0] %= 36;
            if (arr[0]) ans++;
        }
        cout<<ans<<'\n';
    }
} 