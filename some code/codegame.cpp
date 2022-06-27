#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Please enter the border.\n";
	cin>>n;
	int upbor = n, downbor = 1;
	srand(time(NULL));
	int x; x = rand();
	while (x%(n+1) == 0) x = rand();
	x = x%(n+1);
	int t;
	cout<<"Please input a number from 1 to "<<n<<'.'<<'\n';
	while(true) {
		cin>>t;
		if (t > upbor || t < downbor) {
			cout<<"Please input again.\n";
			continue;
		}
		if (t == x) break;
		if (t > x) {
			upbor = t-1;
			cout<<"lower!\n";
		}
		if (t < x) {
			downbor = t+1;
			cout<<"higher!\n";
		}
	}
	cout<<"Congradulations!\n";
	cout<<"The answer is "<<x<<'!'<<'\n';
	return 0;
}


