#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, p ,n;
    cin>>m>>p>>n;
    int wood[n+1];
    for (int i = 0; i < n; i++) {
        cin>>wood[i];
        if (i == 0) {
        	if (wood[0] > m) {
        		cout<<"IMPOSSIBLE\n";
        		return 0;
			}
		} 
        if (i != 0) {
            if (wood[i]-wood[i-1] > m) {
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    wood[n] = p;
    int place = 0;
    int times = 0;
    for (int i = 0; i < n+1; i++) {
        if (wood[i]-place <= m) {
            continue;
        } else {
            i--;
            place = wood[i];
            times++;
            continue;
        }
    }
    cout<<times<<'\n';
    return 0;
}