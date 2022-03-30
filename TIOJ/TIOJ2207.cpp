#include <bits/stdc++.h>
using namespace std;

//001 110  101 010  100 011

int main() {
    int n, k; cin>>n>>k;
    vector <int> guess(n,-1);
    vector <string> s(k);
    vector <queue<int> > compare(8);// 000 001 010 011 100 101 110 111
    for (int i = 0; i < k; ++i) {
        cin>>s[i];
    }
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            cout<<1-(s[0][i]-'0');
        }
        cout<<'\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int counter = 0;
        int cross = 1;
        for (int j = 0; j < k; ++j) {
            counter += cross*(s[j][i]-'0');
            cross *= 2;
        }
        //cout<<counter<<' ';
        if (counter == 0) {
            guess[i] = 1;
        } else if (counter == cross-1) {
            guess[i] = 0;
        } else {
            compare[counter].push(i);
        }
    }
    //for (int i : compare) cout<<i;
    if (k == 3) {
        for (int l = 1; l <= 3; ++l) {
            int x = min(compare[l].size(),compare[7-l].size());
            while(x--) {
                guess[compare[l].front()] = 1;
                guess[compare[7-l].front()] = 1;
                compare[l].pop();
                compare[7-l].pop();
            }
        }
    } else {
        int x = min(compare[1].size(),compare[2].size());
        while(x--) {
            guess[compare[1].front()] = 1;
            guess[compare[2].front()] = 1;
            compare[1].pop();
            compare[2].pop();
        }
        int s1 = compare[1].size();
        int s2 = compare[2].size();
        for (int i = 0; i < s1; ++i) {
            if (i < s1/2) {
                guess[compare[1].front()] = 1;
            } else {
                guess[compare[1].front()] = 0;
            }
            compare[1].pop();
        }
        for (int i = 0; i < s2; ++i) {
            if (i < s1/2) {
                guess[compare[2].front()] = 1;
            } else {
                guess[compare[2].front()] = 0;
            }
            compare[2].pop();
        }
    }
    for (int i : guess) cout<<i;
    cout<<'\n';
    return 0;
}