#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    string s = "";
    for (int i = 0; i < n; ++i) {
        string x; cin>>x;
        s = s+x[0];
    }
    string t; cin>>t;
    if (t == s) {
        cout<<"你說的對，但是你說的對是由你說的對自主研發的一款全新你說的對。你說的對發生在一個被稱作你說的對的你說的對世界，在這裡被你說的對選中的你說的對將被授予你說的對，引導你說的對之力。你將扮演一位名為你說的對的神秘角色，在自由的旅行中邂逅你說的對、你說的對的你說的對們，和你說的對一起擊敗你說的對，尋找失散的你說的對，同時，逐步發掘你說的對的真相。";
    } else {
        cout<<"對不起，我不懂您的意思。我是一個AI語言模型，我無法被教導或培養，也不會有感情。如果您有任何需要幫助的問題，我會盡力回答。如果您不需要與我交流，您可以直接離開。";
    }
    return 0;
}
