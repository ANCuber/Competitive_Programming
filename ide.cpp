#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RANGE 1e-15
using namespace std;
//#define RANGE 0.0000000001
//this is a program to calculate the n Th root of a number.
//change the value of RANGE to determine the variation of the n Th root caculated.

double ROOT(double,int);
double my(double,int);
const double eps = 1e-8;

int main(void) { 
    //printf("Hi I am ???????????!!!!!!\a\n\n");
    //begin:
    double x;
    int y;
    printf("請輸入一個數： ");
    scanf("%lf",&x);
    printf("請輸入一正整數來開幾次方： ");
    scanf("%d",&y);
    if(x<0 && y%2) printf("%.16lf 的 開 %d 次方是 -%.16lf\n",x,y,ROOT(-x,y));
    else if(x<0 &&y==2) printf("%.16lf 的 開 %d 次方是 %.16lf i\n",x,y,ROOT(-x,y));
    else if(x<0 &&y%2==0 || y<=0 ) printf("無定義\n");
    else printf("%.16lf 的 開 %d 次方是 %.16lf\n",x,y,ROOT(x,y));
    system("pause");
    printf("\n");
    //goto begin; 
}

double ROOT(double x,int y) {
    double left,right,mid,g=0,m,j,k,f=0;
    if(x>=1) {
        right=x;left=1;
        /*for(f=0;f<x;f++) if(my(f,y)>=x) break;
        for(j=1;j<10;j++) {
  	        for(m=0;m<10;m++) {
  		        k=my(0.1,j)*m+f;
		        if(k+my(0.1,j)*m>=x) {
                    f=k;
		            break;
  		        }
  	        }
        }*/
    } else {
  	    right=1;left=x;
  	    /*for(j=1;j<10;j++) {
  		    for(m=0;m<10;m++) {
  			    k=my(0.1,j)*m+f;
		  	    if(k+my(0.1,j)*m>=x) {
  				    f=k;
				    break;
  			    }
  		    }
  	    }*/
    }
    printf("左界%.15lf,右界%.15lf\n",left,right);
    //for(m=0;m<x;m++) if(my(m,y)>=x) break;
    while(right-left > eps) {
        if(my((right+left)/2,y) > x) {
            right = (left+right)/2;
        } else {
            left = (left+right)/2;
        }
        printf("左界%.15lf,右界%.15lf\n",left,right);
    } 
    return (right+left)/2;
}

double my(double x,int n) {
    double k = x;
    for(int i=1;i<n;i++) x = x*k;
    return x;
}
