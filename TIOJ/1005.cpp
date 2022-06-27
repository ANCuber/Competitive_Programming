#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}

int main() {
	int n;
	while(1) {
		cin>>n;
		double pi;
		if (n == 0) return 0;
		double s[n];
		double counter = 0;
		for (int i = 0; i < n; i++) {
			cin>>s[i];
		}
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				if (gcd(s[i],s[j]) ==  1) counter++;
			}
		}
		if (counter == 0) {
			cout<<"No estimate for this data set.\n";
			continue;
		}
		pi = 6*(n*(n-1)/2)/counter;
		cout<<fixed<<setprecision(6)<<sqrt(pi)<<'\n';
	}
	return 0;
}
