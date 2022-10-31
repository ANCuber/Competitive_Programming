#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl '\n'
#define pii pair<int,int>
 
int main() {
	ll n, a; cin>>n;
	ll sum = n*(n+1)/2;
	while(--n) {
		cin>>a;
		sum -= a;
	}
	cout<<sum<<endl;
	return 0;
}

