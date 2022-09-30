#include <bits/stdc++.h>
using namespace std;

double ROOT(double,int);
double mypow(double,int);
const double eps = 1e-12;

int main() { 
    double x; int y;
    cout<<"請輸入一個數： ";
    cin>>x;
    cout<<"請輸入一正整數來開幾次方： ";
    cin>>y;
    if(x<0 &&y%2==0 || y<=0 ) {
        printf("無定義\n");
    } else {
        cout<<x<<"的開"<<y<<"次方是:"<<endl;
        cout<<fixed<<setprecision(10)<<ROOT(x,y)<<endl;
    }
    return 0;
}

double ROOT(double x,int y) {
    double left,right, mid;
    if(x>=1) right=x,left=1;
    else right=1,left=x;
    
    //printf("左界%.15lf,右界%.15lf\n",left,right);
    while(right-left > eps) {
        mid = (right+left)/2;
        if(mypow(mid,y) > x) {
            right = mid;
        } else {
            left = mid;
        }
        //printf("左界%.15lf,右界%.15lf\n",left,right);
    }
    return mid;
}

double mypow(double x,int n) {
    double k = x;
    for(int i=1;i<n;i++) x = x*k;
    return x;
}

