#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long n, q; cin>>n>>q;
    vector <long long> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        sum += arr[i];
    }
    bitset <200005> ctrl(false);
    long long num;
    for (int i = 0; i < q; ++i) {
        int t; cin>>t;
        if (t == 1) {
            long long id, x; cin>>id>>x;
            if (ctrl[id-1]) {
                sum -= num;
                sum += x;
                arr[id-1] = x;
            } else {
                sum -= arr[id-1];
                arr[id-1] = x;
                sum += x;
            }
            ctrl[id-1] = false;
        } else if (t == 2){
            cin>>num;
            sum = n*num;
            ctrl.set();
        }
        cout<<sum<<endl;
    }
    return 0;
}