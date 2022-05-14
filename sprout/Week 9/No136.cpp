#include <bits/stdc++.h>
using namespace std;

//meet in middle algorithm

#define endl '\n'

void Report(long long id) {
    cout<<id<<endl;
}


void solve(long long n, long long k, long long a[]) {
    pair <long long,long long> store[1LL<<(n/2)];
    for (long long i = 0; i < (1LL<<(n/2)); ++i) {
        long long sum = 0;
        for (long long j = 0; j < n/2; ++j) {
            sum += a[j]*((i>>j)&1);
        }
        store[i] = {sum,i};
    }
    sort(store,store+(1LL<<(n/2)));
    for (long long i = 0; i < (1LL<<(n-n/2)); ++i) {
        long long sum = 0;
        for (long long j = 0; j < n-n/2; ++j) {
            sum += a[j+n/2]*((i>>j)&1);
        }

        long long l = 0;
        long long r = 1LL<<(n/2);
        long long mid = l+(r-l)/2;
        while (r-l > 1) {
            if (store[mid].first > k-sum) {
                r = mid;
            } else {
                l = mid;
            }
            mid = l+(r-l)/2;
        }
        if (store[l].first == k-sum) {
            long long all = store[l].second + ((1LL*i)<<(n/2));
            for (long long i = 0; i < n; ++i) {
                if ((all>>i)&1) Report(i+1);
            }
            Report(-1);
            return;
        }
    }
    Report(-1);
    return;
}

int main() {
    long long n; cin>>n;
    long long k; cin>>k;
    long long a[n];
    for (long long i = 0; i < n; ++i) {
        cin>>a[i];
    }
    solve(n,k,a);
    return 0;
}