#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

void MergeSort(vector<int> &a, int L, int R) {
    if (L == R) return;
    int M = (L+R)/2;
    MergeSort(a,L,M), MergeSort(a,M+1,R);
    int pl = L, pr = M+1;
    vector<int> tmp;
    while(pl <= M && pr <= R) {
        if (a[pl] <= a[pr]) tmp.push_back(a[pl++]);
        else tmp.push_back(a[pr++]);
    }
    while(pl <= M) tmp.push_back(a[pl++]);
    while(pr <= R) tmp.push_back(a[pr++]);
    for (int i = L; i <= R; ++i) a[i] = tmp[i-L];
}

