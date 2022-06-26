#include <bits/stdc++.h>
using namespace std;

struct infor {
    int c; 
    int e;
    bool operator<(infor b) {
        if (e > b.e) return 1;
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        if (!n) break;
        vector <infor> arr(n);
        for (int i = 0; i < n; ++i) {
            cin>>arr[i].c>>arr[i].e;
        }
        sort(arr.begin(), arr.end());
        int sum = 0;
        int longest = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i].c;
            if (longest < sum+arr[i].e) longest = sum+arr[i].e;
        }
        cout<<longest<<'\n';
    }
    return 0;
}