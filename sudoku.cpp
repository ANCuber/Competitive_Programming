#include <bits/stdc++.h>
using namespace std;

const int RECURSION_MAX = 100'000'000;
int recursion_cnt = 0;
bool input[9][9]; // input[i][j] == true means this grid is not zero in your input
int board[9][9];
bool column_used[9][9]; // column_used[i][j] == true means "j" has been used in column i
bool row_used[9][9]; // row_used[i][j] == true means "j" has been used in row i
bool area_used[3][3][9]; // area_used[i][j][k] == true means "k" has been used in 3x3 area (i, j)

void increase_recursion_cnt() {
    recursion_cnt++;
    if (recursion_cnt >= RECURSION_MAX) {
        cout << "Recursion count: >= 100000000" << endl;
        exit(0);
    }
}

void print_solution() {
    for (int i = 0; i < 9; ++ i)
        for (int j = 0; j < 9; ++ j) {
            cout << board[i][j];
            if (j == 8) cout << endl;
            else cout << ' ';
        }
}

bool Sudoku(int r, int c) {
    increase_recursion_cnt();

    if (r == 9) { // found a solution!
        print_solution();
        return true;
    }
    if (input[r][c] == true && ((c < 8 && Sudoku(r, c + 1)) || (c == 8 && Sudoku(r + 1, 0)))) { // this grid is not empty
        return true;
    } else if (input[r][c] == false) { // this grid is empty
        for (int i = 0; i < 9; ++ i) {
            if (!column_used[c][i] && !row_used[r][i] && !area_used[r / 3][c / 3][i]) { // check if "i" can be put into this gird
                board[r][c] = i + 1;
                column_used[c][i] = true;
                row_used[r][i] = true;
                area_used[r / 3][c / 3][i] = true;
                if ((c < 8 && Sudoku(r, c + 1)) || (c == 8 && Sudoku(r + 1, 0)))
                    return true;
                column_used[c][i] = false;
                row_used[r][i] = false;
                area_used[r / 3][c / 3][i] = false;
            }
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; ++ i) {
        for (int j = 0; j < 9; ++ j) {
            cin >> board[i][j];
            if (board[i][j] < 0 || board[i][j] > 9) return -1;
            if (board[i][j] != 0) {
                input[i][j] = true;
                if (column_used[j][board[i][j] - 1] || row_used[i][board[i][j] - 1] || area_used[i / 3][j / 3][board[i][j] - 1])
                    return -1;
                column_used[j][board[i][j] - 1] = true;
                row_used[i][board[i][j] - 1] = true;
                area_used[i / 3][j / 3][board[i][j] - 1] = true;
            }
        }
    }
    bool result = Sudoku(0, 0);
    if (!result) {
        cout << "No solution!" << endl;
    }
    cout << "Recursion count: " << recursion_cnt << endl;
}
