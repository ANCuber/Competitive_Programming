#include <bits/stdc++.h>

using namespace std;

struct items
{
	int w;
	int f;
	bool operator<(items b)
	{
		if (w*b.f - b.w*f != 0)
			return (w*b.f - b.w*f > 0);
		return f > b.f;
	}
};

items item[100005];
unsigned long long int e = 0;

int main()
{
	int n;
	while (cin>>n)
	{
		for (int i = 1; i <= n; i++) cin>>item[i].w;
		for (int i = 1; i <= n; i++) cin>>item[i].f;
		sort(item + 1, item + n + 1);
		unsigned long long int wsum = 0;
		for (int i = n - 1; i >= 1; i--)
		{
			wsum += item[i + 1].w;
			e += wsum*item[i].f;
		}
		cout<<e<<'\n';
	}
	return 0;
}
