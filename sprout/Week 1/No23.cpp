#include <bits/stdc++.h>
using namespace std;

void push_train();
void pop_train();
void move_station_1_to_2();
void move_station_2_to_1();

void solve(int N, int order[]) {
    stack <int> gt02, gt01;
    for (int i = 1; i <= N; ++i) {
        push_train();
        gt01.push(i);
    }
    vector <int> tp(N+1,1);
    for (int i = 0; i < N; ++i) {
        int goal = order[i];
        if (tp[goal]==1) {
            while(gt01.top() != goal) {
                tp[gt01.top()] = 2;
                gt02.push(gt01.top());
                gt01.pop();
                move_station_1_to_2();
            }
            gt02.push(gt01.top());
            gt01.pop();
            move_station_1_to_2();
        } else if (tp[goal]==2){
            while(gt02.top() != goal) {
                tp[gt02.top()] = 1;
                gt01.push(gt02.top());
                gt02.pop();
                move_station_2_to_1();
            }
        }
        pop_train();
        tp[goal]=3;
        gt02.pop();
    }
}