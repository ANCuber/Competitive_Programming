#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

long double IntRate = 1.0172;
const long double esp = 1e-10;//If you can't see the result, please try a different (maybe larger) value.

long double pow(long double a, ll x) {
    long double ret = 1.0;
    while(x) {
        if (x&1) ret *= a;
        a *= a;
        x >>= 1;
    }
    return ret;
}

long double root(long double a) {
    long double l = 0, r = 2, m;
    while(r-l > esp) {
        m = (l+r)/2;
        if (pow(m,12) > a) r = m;
        else l = m;
    }
    return (l+r)/2;
}

bool CheckEMI(long double L, ll P, long double x) {
    for (int i = 0; i < P; ++i) {
        L *= IntRate;
        L -= x;
    }
    return L <= 0;
}

void EMI(long double L, ll P) {
    long double l = 0, r = L*10, m;
    while(r-l > esp) {
        m = (r-l)/2+l;
        if (CheckEMI(L,P,m)) r = m;
        else l = m;
    }
    m = (r-l)/2+l;
    cout<<"You need to pay NTD "<<m<<" each month."<<endl;
}

inline void EPP(long double Loan, ll P) {
    cout<<"You need to reduce the principal by NTD "<<Loan/P<<" each month."<<endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout<<fixed<<setprecision(5);
    long double Loan;
    ll Period;
    //IntRate = 1+(IntRate-1)/12;//Note: Only the results of this setting align with online tools.
    IntRate = root(IntRate);//Note: However, this setting should be the correct one instead.
    cout<<"Please enter how much money the bank has lent you."<<endl;
    cin>>Loan;
    cout<<"Please enter how many months you will be paying."<<endl;
    cin>>Period;
    if (!Period) {
        cout<<"Well...not even possible!"<<endl;
        return 0;
    }
    cout<<"Assuming EMI:"<<endl;
    EMI(Loan,Period);
    cout<<"Assuming EPP:"<<endl;
    EPP(Loan,Period);
    return 0;
}
