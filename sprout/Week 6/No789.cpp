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
    }
    int subsize = n-(n>>1);
    vector <int> subarr(subsize,0);
    solve(subarr,subsize);
    for (int i = 0; i < subsize; i++) {
        arr[i] = (subarr[i]<<1)-1;
    }
    int id = 0;
    for (int i = subsize; i < n; i++,id++) {
        if ((subarr[id]<<1) > n) {
            i--;
            continue;
        }
        arr[i] = subarr[id]<<1;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <int> arr(n,0);
    solve(arr,n);
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' ';
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}