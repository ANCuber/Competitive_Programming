#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin>>n>>m;
    vector <int> begginer(n+1,-1);
    vector <int> last(n+1,-1);
    vector <int> nextotaku(1000005,-1);
    for (int l = 1; l <= m; l++) {
        string x; cin>>x;
        if (x[0] == 'A') {
            int i, id; cin>>i>>id;
            if (begginer[i] == -1) {
                begginer[i] = id;
            } else {
                nextotaku[last[i]] = id;
            }
            last[i] = id;
            nextotaku[id] = -1;
        } else if (x[0] == 'L') {
            int i; cin>>i;
            if (begginer[i] == -1) {
                cout<<"queue "<<i<<" is empty!\n";
                continue;
            }
            int a = begginer[i];
            begginer[i] = nextotaku[a];
            nextotaku[a] = -1;
        } else {
            int i, j; cin>>i>>j;
            if (begginer[i] == -1) continue;
            if (begginer[j] == -1) {
                begginer[j] = begginer[i];
                last[j] = last[i];
            } else {
                nextotaku[last[j]] = begginer[i];
                last[j] = last[i];
                nextotaku[last[j]] = -1;
            }
            begginer[i] = -1;
            last[i] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        int ptr = begginer[i];
        if (ptr == -1) cout<<"queue "<<i<<": empty";
        else cout<<"queue "<<i<<":";
        while(ptr != -1) {
            cout<<' '<<ptr;
            ptr = nextotaku[ptr];
        }
        cout<<'\n';
    }
    return 0;
}