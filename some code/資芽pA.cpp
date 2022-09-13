#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	long long n, m;
	int k;
	cin>>n>>m>>k;
	if (k == 0) {
		if ((m*n) % 6 == 0) cout<<(m*n) / 6<<'\n';
		else cout<<(m*n)/6 + 1<<'\n';
		return 0;
	}
	long long roaddis = m*n;
	vector <long long> snakes;
	for (int i = 0; i < k; i++) {
		int xi, yi;
		cin>>xi>>yi;
		if (xi % 2 == 1) snakes.emplace_back((xi-1)*m + yi);
		else snakes.emplace_back((xi-1)*m + (m-yi+1));
	}
	sort(snakes.begin(), snakes.end());
	long long counter = 0, backstep = 0;
	for (long long i = 0, j; i < k; i++) {
		backstep = 0;
		j = i;
		long long cur = snakes[i];
		while ((cur+backstep+counter)%6 == 0) {
			backstep++;
			if (backstep == 6) {
				cout<<"-1\n";
				return 0;
			}
			if (cur-snakes[j-1] == 1) {
				j--;
				cur = snakes[j];
			}
			else break;
		}
		counter += backstep;
	}
	cout<<(n*m+counter)/6 + ((n*m+counter)%6 != 0)<<'\n';
	return 0;
}
