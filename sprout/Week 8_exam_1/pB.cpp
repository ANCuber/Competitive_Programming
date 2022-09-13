#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool rever = 0;
int k;

struct number{
    int num;
    bool mod = 0;
    number *left = nullptr;
    number *right = nullptr;
};

number* root = new number;
number* ender = new number;

void ADD (int x) {
    number* newer;
    if (rever) {
        newer->right = ender->right;
        root->right->left = newer;
        newer->num = x;
        root->right = newer;
        newer->left = root;
    } else {
        newer->left = ender->left;
        ender->left->right = newer;
        newer->num = x;
        ender->left = newer;
        newer->right = ender;
    }
}

void REMOVE() {
    ender->left->left->right = ender;
    ender->left = ender->left->left;
}

void MOD() {

}

void CHANGE() {
    
}

int main() {
    int q; cin>>k>>q;
    root->mod = true;
    ender->mod = true;
    root->right = ender;
    ender->left = root;
    int len = 0;
    for (int i = 0; i < q; ++i) {
        string c; cin>>c;
        if (c[0] == 'A') {
            int x; cin>>x;
            ADD(x);
            len++;
        } else if (c[2] == 'm') {
            REMOVE();
        } else if (c[0] == 'M') {
            MOD();
        } else {
            CHANGE();
        }
    }
    number* ptr = root;
    while(ptr->right != ender) {
        cout<<ptr->right->num<<' ';
        ptr = ptr->right;
    }
}