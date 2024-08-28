#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
#include "lib0593.h"
using namespace std;

#define ll long long
#define pb push_back

void selection_sort(int array[], int size) {
    sort(array,array+size);
    for (int i = 0; i < size; ++i) {
        if (i) cout<<' ';
        cout<<arr[i];
    }
}

