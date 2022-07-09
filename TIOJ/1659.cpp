#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    bitset <5005> arr(0);
    arr[2] = arr[3] = 1;
    for (int i = 4; i <= 5000; ++i) {
        int ctrl = 1;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) ctrl = 0;
        }
        if (ctrl) arr[i] = 1;
        else arr[i] = 0;
    }
    int n;
    while(cin>>n) {
        cout<<"primes between 1 ~ "<<n<<":";
        for (int i = 2; i <= n; ++i) {
            if (arr[i]) cout<<" "<<i;
        }
        cout<<endl;
    }
    return 0;
}
