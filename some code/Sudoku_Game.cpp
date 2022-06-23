#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int problem[9][9] = {0};
string start_cmd;

struct input{int i, j, k;};

void Print_Rules() {
    cout<<"Iuput \"i j k\" to fill the blank (i,j) in Cartesian coordinate system(1-based) with k.\n";
    cout<<"Input \"0 0 0\" to quit the game.\n";
    return;
}

input Iuput() {
    int ii , jj , kk;
    cin>>ii>>jj>>kk;
    input ret;
    ret.i = 9-jj;
    ret.j = 9-ii;
    ret.k = kk;
    return ret;
}

void Generate() {

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<"Welcome to the sudoku game!!!\n";
    cout<<"Please enter \"start\" to play or enter \"quit\" to leave.\n";
    while(true) {
        cin>>start_cmd;
        if (start_cmd == "start") {
            Print_Rules();
            Generate();
            break;
        } else if (start_cmd == "quit") {
            break;
        } else {
            cout<<"Invalid command, please enter a command again.\n";
        }
    }
    return 0;
}