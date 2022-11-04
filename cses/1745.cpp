#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

const int maxn = 1e5;

int n, a;
vector<bitset<maxn+5> > arr(2);

signed main() {
    scanf("%d",&n);  
    arr[0].reset(), arr[1].reset();
    arr[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a);
        for (int j = 0; j <= maxn; ++j) {
            if (j >= a) arr[i%2][j] = max(arr[(i+1)%2][j-a],arr[(i+1)%2][j]);
            else arr[i%2][j] = arr[(i+1)%2][j];
        }
    }
    int ans = arr[n%2].count(), flag = 0;
    printf("%d\n",ans-1);
    for (int i = 1; i <= maxn; ++i) {
        if (arr[n%2][i]) {
            if (!flag) printf("%d",i);
            else printf(" %d",i);
            flag = 1;
        }
    }
    printf("\n");
    return 0;
}
