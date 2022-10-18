#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

struct Nd{
    int id, val, num;
};

bool cmp(Nd a, Nd b) {
    if (a.val == b.val) return a.id < b.id;
    return a.val < b.val;
}

int cnt(int a) {
    int ans = 0;
    while(a) {
        a -= (a&-a);
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<Nd> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i].id = i;
        cin>>arr[i].num;
        arr[i].val = cnt(arr[i].num);
    }
    sort (arr.begin(),arr.end(),cmp);
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' ';
        cout<<arr[i].num;
    }
    cout<<endl;
    return 0;
}
