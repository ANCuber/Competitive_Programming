#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

const int MAXN = 1e6;

struct BIT {
    vector<int> arr, a;
    int sz = 0;

    void add(int v) {
        a[v]++;
        sz++;
        while(v <= MAXN) {
            arr[v]++;
            v += (v&-v);
        }
    }
    int sum(int p) {
        int ans = 0;
        while(p > 0) {
            ans += arr[p];
            p -= (p&-p);
        }
        return ans;
    }
    int query(int k) {
        int l = 1, r = MAXN+1;
        int mid = (l+r)>>1;
        while(r-l>1) {
            int sm = sum(mid);
            if (sm < k) {
                l = mid;
            } else {
                if (a[mid] && sm-a[mid] < k) return mid;
                r = mid;
            }
            mid = (l+r)>>1;
        }
        return mid;
    }
} bit;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q; cin>>q;    
    int cmd, x;
    bit.arr.assign(MAXN+5,0);
    bit.a.assign(MAXN+5,0);
    while(q--) {
        cin>>cmd;
        if (cmd == 1) {
            cin>>x;
            bit.add(x);
        } else {
            cout<<bit.query((bit.sz+1)>>1)<<endl;
        }
    }
    return 0;
}

