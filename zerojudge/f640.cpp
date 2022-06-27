#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

string x;
int gg[2] = {2,1}; 
int hh[3] = {3,-2,1};

int f();
int h();
int g();

int f() {
    cin>>x;
    if (x == "f") {
        return 2*f()-3;
    } else if(x == "g"){
        return 2*g()-3;
    } else if(x == "h"){
        return 2*h()-3;
    } else {
        return 2*stoi(x) - 3;
    }
}

int g() {
    int ret = -7;
    for (int i = 0; i < 2; ++i) {
        cin>>x;
        if (x == "f") {
            ret += gg[i]*f();
        } else if(x == "g"){
            ret += gg[i]*g();
        } else if(x == "h"){
            ret += gg[i]*h();
        } else {
            ret += gg[i]*stoi(x);
        }
    }
    return ret;
}

int h() {
    int ret = 0;
    for (int i = 0; i < 3; ++i) {
        cin>>x;
        if (x == "f") {
            ret += hh[i]*f();
        } else if(x == "g"){
            ret += hh[i]*g();
        } else if(x == "h"){
            ret += hh[i]*h();
        } else {
            ret += hh[i]*stoi(x);
        }
    }
    return ret;
}

int main() {
    cin>>x;
    if (x == "f") {
        cout<<f()<<endl;
    } else if(x == "g"){
        cout<<g()<<endl;
    } else {
        cout<<h()<<endl;
    }
    return 0;
}