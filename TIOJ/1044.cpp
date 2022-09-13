#include <bits/stdc++.h>
#include "lib1044.h"
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    int n = Initialize();
    int l = 0;
    int r = n+1;
    int Q = (l+r)>>1;
    while(r - l > 1) {
        if (Guess(Q)) {
            r = Q;
        } else {
            l = Q;
        }
        Q = (l+r)>>1;
    }
    Report(r);
    return 0;
}