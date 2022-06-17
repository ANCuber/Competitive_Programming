#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n, q;

struct Nd{
    int mx = 0;
    int tag = 0;
    int chg = 0;
};

vector<Nd> seg;
vector<int> arr;

void init(int l, int r, int node) {
    
}


void push(int node) {
    
}

void query() {

}

void add() {

}

void change() {

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q;
    seg.resize(n<<2);
    arr.resize(n+1);
    int cmd;
    int l, r, x;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
    }
    while(q--){
        cin>>cmd;
        if (cmd == 1) {
            cin>>x;

        } else if (cmd == 2) {

        } else {
            cin>>x;

        }
    }
}