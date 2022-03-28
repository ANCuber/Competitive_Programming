#include <bits/stdc++.h>
using namespace std;

deque <int> numbers;


int main() {
    int n; cin>>n;
    int a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        numbers.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x = numbers.front();
        int y = numbers.back();
        if (i == n-1) {
            if (i%2 == 0) {
                a += x;
            } else {
                b += x;
            }
            break;
        }
         if (x > y) {
            if (i%2 == 0) {
                a += x;
            } else {
                b += x;
            }
            numbers.pop_front();
        }
        else if (x < y) {
            if (i%2 == 0) {
                a += y;
            } else {
                b += y;
            }
            numbers.pop_back();
        }
        else if (x == y) {
            
        }
    }
    cout<<a<<' '<<b<<'\n';
    return 0;
}