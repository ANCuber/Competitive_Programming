#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

struct Card{
    char type;
    int num;
    bool operator<(Card b) {
        if (num == b.num) return (type-'A') > (b.type-'A');
        return num > b.num;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<Card> c(n);
    for (auto& i : c) cin>>i.type>>i.num;
    sort(c.begin(),c.end());
    int m; cin>>m;
    m--;
    cout<<c[m].type<<' '<<c[m].num<<endl;
    return 0;
}
