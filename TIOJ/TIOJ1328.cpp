#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    int n;
    while(true) {
        scanf("%d",&n);
        if (!n) break;
        for (int i = 1; i <= n; ++i) {
            if (i-1) printf("%c",' ');
            printf("%d",i);
        }
        printf("%c",'\n');
    }
    return 0;
}