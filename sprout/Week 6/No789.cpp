#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(vector <int> &arr,int n) {
    if (n == 1) {
        arr[0] = 1;
        return;
    } else if (n == 2) {
        arr[0] = 1;
        arr[1] = 2;
        return;
    } else if (n == 3) {
        arr[0] = 3;
        arr[1] = 1;
        arr[2] = 2;
        return;
    } else if (n == 4) {
        arr[0] = 1;
        arr[1] = 3;
        arr[2] = 2;
        arr[3] = 4;
    }
    int subsize = n-n/2;
    vector <int> subarr(subsize,0);
    solve(subarr,subsize);
    for (int i = 0; i < subsize; i++) {
        arr[i] = subarr[i]*2-1;
    }
    int id = 0;
    for (int i = subsize; i < n; i++,id++) {
        if (subarr[id]*2 > n) {
            i--;
            continue;
        }
        arr[i] = subarr[id]*2;
    }
    /* cout<<"# "<<n<<":";
    for (auto i : arr) cout<<i<<' ';
    cout<<endl<<endl; */
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <int> arr(n,0);
    solve(arr,n);
    vector <int> x(n,0);
    for (int i = 0; i < n; ++i) {
        cout<<arr[i];
        if (i == n-1) cout<<'\n';
        else cout<<' ';
    }
    return 0;
}