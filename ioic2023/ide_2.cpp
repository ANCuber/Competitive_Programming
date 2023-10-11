#include <bits/stdc++.h>
using namespace std;

int cmp(int x, int y, int z)
{
    if (x < 0) return y;
    else if (x > 0) return z;
    else return 0;
}

#define int long long

const int CLOCKWISE = -1, PARALLEL = 0, COUNTERCLOCKWISE = 1;
string output[] = { "clockwise", "parallel", "counterclockwise" };

main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int cross = a * d - b * c;
    int sign = cmp(cross, CLOCKWISE, COUNTERCLOCKWISE);
    cout << output[sign + 1] << '\n';
}

