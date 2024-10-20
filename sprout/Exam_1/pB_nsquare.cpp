#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int q, k; cin>>k>>q;
    deque <int> arr;
    bool rever = 0;
    int len = 0;
    for (int i = 0; i < q; ++i) {
        string c; cin>>c;
        if (c[0] == 'A') {
            int x; cin>>x;
            if (rever) {
                arr.push_front(x);
            } else {
                arr.push_back(x);
            }
            len++;
        } else if (c[2] == 'm') {
            int mid = len>>1;
            if (rever) {
                int i = arr.size()-1;
                int id = arr.size()-1;
                while(i>mid) {
                    if (arr[i] != -1) i--;
                    id--;
                }
                arr[id] = -1;
            } else {
                int i = 0;
                int id = 0;
                while(i<mid) {
                    if (arr[i] != -1) i++;
                    id++;
                }
                arr[id] = -1;
            }
        } else if (c[0] == 'M') {
            for (int i = 0; i < arr.size(); ++i) {
                if (arr[i] != -1) arr[i] %= k;
            }
        } else {
            rever = 1-rever;
        }

         if (rever) {
        for (int i = arr.size()-1; i >= 0; --i) {
            if (arr[i] != -1) cout<<arr[i]<<' ';
        }
    } else {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] != -1) cout<<arr[i]<<' ';
        }
    }

    }
    if (rever) {
        for (int i = arr.size()-1; i >= 0; --i) {
            if (arr[i] != -1) cout<<arr[i]<<' ';
        }
    } else {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] != -1) cout<<arr[i]<<' ';
        }
    }
    cout<<endl;
    return 0;
}