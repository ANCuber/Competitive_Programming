#include <bits/stdc++.h>
using namespace std;

int n,k;

struct Horse{
    long long able;
    long long grow;
};

vector <Horse> horse;
vector <int> c;

bool judge(int m) {
    vector <long long> ability(n,0);
    for (int i = 0; i < n; ++i) {
        ability[i] = horse[i].able + m*horse[i].grow;
    }
    sort(ability.begin(),ability.end());
    int won = 0;
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (index >= n) break;
        if (ability[index] <= c[i]) i--;
        else {
            won++;
        }
        index++;
    }
    if (won >= k) return 1;
    else return 0;
}

int main() {
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        horse.resize(n);
        c.resize(n);
        for (int i = 0; i < n; ++i) 
            cin>>horse[i].able>>horse[i].grow;
        for (int i = 0; i < n; ++i) 
            cin>>c[i];
        sort(c.begin(),c.end());
        int high = 1e9;
        int low = 0;
        int guess = (high+low)/2;
        int director = 0;
        while(high > low) {
            if (!judge(guess)) {
                low = guess+1;
            } else {
                high = guess;
                director = 1;
            }
            guess = (high+low)/2;
        }
        if (director) cout<<guess<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;
}