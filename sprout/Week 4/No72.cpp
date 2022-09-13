#include <bits/stdc++.h>
using namespace std;

int n;

struct f_of_t {
    long double a, b, c;
};

vector <f_of_t> problem;

long double f (long double a, long double b, long double c, long double t) {
    return a*(t-b)*(t-b) + c;
}

long double s(long double t) {
    long double max = -1;
    for (int i = 1; i <= n; ++i) {
        long double x = f(problem[i].a,problem[i].b,problem[i].c,t);
        if (x > max) max = x;
    }
    return max;
}

int main() {
    int testdata; cin>>testdata;
    while(testdata--) {
        cin>>n;
        problem.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            cin>>problem[i].a>>problem[i].b>>problem[i].c;
        }
        long double high = 300;
        long double low = 0;
        long double gh = 200;// 2/3
        long double gl = 100;// 1/3
        while(high-low >= 1e-12) {
            if (s(gl) == s(gh)) {
                high = gh;
                low = gl;
            } else if (s(gl)>s(gh)) {
                low = gl;
            } else if (s(gl)<s(gh)){
                high = gh;
            }
            gh = (2*high+low)/3;
            gl = (2*low+high)/3;
        }
        cout<<fixed<<setprecision(12)<<s((low+high)/2)<<'\n';
    }
    return 0;
}