#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    vector <int> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        sum += arr[i];
    }
    bitset <200005> ctrl(0);
    int num;
    for (int i = 0; i < q; ++i) {
        int t; cin>>t;
        if (t == 1) {
            int id, x; cin>>id>>x;
            if (ctrl[id-1]) {
                sum -= num;
                sum += x;
                arr[id-1] = x;
                ctrl[id-1] = false;
            } else {
                sum -= arr[id-1];
                arr[id-1] = x;
                sum += x;
            }
        } else if (t == 2){
            int x; cin>>x;
            sum = (long long)(n*x);
            ctrl.set();
            num = x;
        }
        cout<<sum<<endl;
    }
}