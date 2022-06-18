#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> arr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    int c = m-1;
    arr.assign(n+1,0);
    int sum = 0;
    for (int i = 1;i <= n; ++i) {
        cin>>arr[i];
        sum += arr[i];
    }
    vector <int> v;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < arr[i]; ++j) {
            v.push_back(i);
        }
    }
    srand(time(NULL));
    while(m--) {
        if (m != c) cout<<' ';
        int cur = rand()%sum;
        cout<<v[cur];
    }
    cout<<endl;
    return 0;
}