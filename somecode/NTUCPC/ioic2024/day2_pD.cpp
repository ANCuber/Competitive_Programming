#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string K; cin>>K;    
    int sum = 0;
    for (int i = 0; i < K.size(); ++i) sum += K[i]-'0';
    if (sum%3 == 0) {
        cout<<K;
    } else {
        int pos, cur = sum%3, m1 = 0, m2 = 0;
        for (int i = 0; i < K.size(); ++i) {
            if ((K[i]-'0')%3 == 1) m1++;
            else if ((K[i]-'0')%3 == 2) m2++;
        }
        int flag = 0;
        if (cur == 1) {
            if (m2) {
                for (int i = 0; i < K.size(); ++i) {
                    if ((K[i]-'0')%3 == 2 && !flag) {
                        flag++;
                        cout<<'-'<<K[i];
                    }
                    else cout<<'+'<<K[i];
                }
            } else if (m1 >= 2) {
                for (int i = 0; i < K.size(); ++i) {
                    if ((K[i]-'0')%3 == 1 && flag < 2) {
                        flag++;
                        cout<<'-'<<K[i];
                    }
                    else cout<<'+'<<K[i];
                }

            } else {
                cout<<"NO";
            }
        } else {
            if (m1) {
                for (int i = 0; i < K.size(); ++i) {
                    if ((K[i]-'0')%3 == 1 && !flag) {
                        flag++;
                        cout<<'-'<<K[i];
                    }
                    else cout<<'+'<<K[i];
                }
            } else if (m2 >= 2) {
                for (int i = 0; i < K.size(); ++i) {
                    if ((K[i]-'0')%3 == 2 && flag < 2) {
                        flag++;
                        cout<<'-'<<K[i];
                    }
                    else cout<<'+'<<K[i];
                }

            } else {
                cout<<"NO";
            }

        }
    } 
    cout<<endl;
    return 0;
}
