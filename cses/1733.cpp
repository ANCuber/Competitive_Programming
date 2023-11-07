#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int P = 1e9+7;
const int B = 27;

int power(int a, int x) {   
    int ret = 1, bs = a;
    while(x) {
        if (x&1) ret = ret*bs%P;
        bs = bs*bs%P;
        x >>= 1;
    }
    return ret;
}

vector<int> Hash(string &s) {
    vector<int> a(s.size()+5,0);
    int bs = B;
    a[0] = (s[0]-'a'+1);
    for (int i = 1; i < s.size(); ++i) {
        a[i] = (a[i-1]+(s[i]-'a'+1)*bs%P)%P;
        bs = bs*B%P;
    }
    return a;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin>>s;    
    int n = s.size();
    vector<int> h = Hash(s), inv(n+5);
    for (int i = 0; i <= n; ++i) inv[i] = power(power(B,i),P-2);
    //for (int i = 0; i < n; ++i) cout<<h[i]<<' '; cout<<endl;
    for (int i = 1; i < n; ++i) {//length
        int cur = h[i-1], cnt = 1;
        //cout<<i<<":"<<cur<<":";
        for (int j = i; j < n; j += i) {
            if (j+i-1 >= n) break;
            int tmp = (h[j+i-1]-h[j-1]+P)%P*inv[j]%P;
            if (tmp == cur) cnt++;
            //cout<<tmp<<' ';
        }
        //cout<<endl;
        if (n%i && (h[n-1]-h[n-1-n%i]+P)%P*inv[n-n%i]%P == h[n%i-1]) cnt++;
        if (cnt == n/i+(n%i!=0)) cout<<i<<' ';
    }
    cout<<n<<endl;
    return 0;
}

