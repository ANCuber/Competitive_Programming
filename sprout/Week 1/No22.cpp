#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector <int> knight(n);
        for (int i = 0; i < n; ++i) {
            cin>>knight[i];
        }
        vector <int> stk;
        int amount;
        long long ans = 0;
        stk.push_back(0);
        for (int i = 1; i < n; ++i) {
            amount = 0;
            while (!stk.empty() && knight[stk.back()] < knight[i]) {
                stk.pop_back();
                amount++;
            }
            if (!stk.empty()) {
                if (knight[i] == knight[stk.back()]) {
                    if (knight[i] == knight[stk[0]]) {
                        amount += stk.size();
                        //cout<<"pass1 "<<amount<<'\n';
                    } else {
                        int front = 0;
                        int last = stk.size()-2;
                        int guess = (last+front)/2;
                        while (last>=front) {
                            if (knight[stk[guess]] == knight[i]) {
                                last = guess-1;
                            } else {
                                front = guess+1;
                            }
                            guess = (last+front)/2;
                        }
                        amount += stk.size()-guess;
                        //cout<<"pass2 "<<amount<<'\n';
                    }
                } else {
                    amount++;
                    //cout<<"pass3 "<<amount<<'\n';
                }
            } else {
                //cout<<"pass4 "<<amount<<'\n';
            }
            ans += (long long) amount;
            stk.push_back(i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}