#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *lchild = nullptr;
    Node *rchild = nullptr;
};
Node *root = new Node;

void Build (Node *newnode, Node *r) {
    if (newnode->data < r->data) {
        if (r->lchild) {
            Build (newnode, r->lchild);
        } else {
            r->lchild = newnode;
            return;
        }
    } else {
        if (r->rchild) {
            Build (newnode, r->rchild);
        } else {
            r->rchild = newnode;
            return;
        }
    }
}


void Postorder(Node *p) {
    if (p->lchild != nullptr)
        Postorder(p->lchild);
    if (p->rchild != nullptr)
        Postorder(p->rchild);
    cout<<p->data<<'\n';
}

int main() {
    int n; cin>>n;
    int k; cin>>k;
    root->data = k;
    for (int i = 1; i < n; ++i) {
        cin>>k;
        Node *next = new Node;
        next->data = k;
        Build (next,root);
    }
    Postorder(root);
    return 0;
}