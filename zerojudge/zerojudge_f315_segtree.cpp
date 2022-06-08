#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

vector <int> st;
vector <int> arr;
vector <vector<int> > id;

void query(int node, int num, int ql, int qr, int l, int r) {
    
}

int main() {
    int n; cin>>n;
    st.resize(n<<3,0);
    arr.resize((n<<1)+1);
    id.resize(n+1);
    for (int i = 1; i <= (n<<1); ++i) {
        cin>>arr[i];
        id[arr[i]].push_back(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {

    }
    cout<<ans<<endl;
    return 0;
}