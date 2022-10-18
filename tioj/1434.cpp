#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

string ans[2] = {"schedulable","unschedulable"};

struct Infor{
    int t;
    int due;
    bool operator<(Infor b) {
        //if (due == b.due) return t < t.b;
        return due < b.due;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    while (n--) {
        int m; cin>>m;
        int ctrl = 0;
        vector<Infor> a(m);
        for (int i = 0; i < m; ++i) {
            cin>>a[i].t>>a[i].due;
        }
        sort(a.begin(),a.end());
        int time = 0;
        for (int i = 0; i < m; ++i) {
            time += a[i].t;
            if (time > a[i].due) ctrl = 1;
        }
        cout<<ans[ctrl]<<endl;
    }
    return 0;
}
