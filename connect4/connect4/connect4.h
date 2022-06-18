// Comment out the next line to disable game board output
#define CONNECT4_DEBUG

// Uncomment the next line to interactively play with your own code
#define CONNECT4_INTERACTIVE

#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <utility>
#include <vector>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

namespace connect4_judge {

static const std::pair<int, int> board_size = {6, 7}; // row * column

class Game {
  public:
    enum Result {
        ONGOING,
        TIE,
        P1_WIN,
        P2_WIN,
        INVALID_MOVE,
    };

    std::vector<std::vector<int>> board; // 0: empty, 1: P1, 2: P2
    int turn;
    Result status;

    Game(): board(board_size.first, std::vector<int>(board_size.second, 0)), turn(1), status(ONGOING) {}
    Result play(int col) {
        if (status != ONGOING)
            return INVALID_MOVE; // Already ended
        if (col < 0 || col >= board_size.second)
            return INVALID_MOVE; // Not a valid column
        if (board[0][col] != 0)
            return INVALID_MOVE; // Top out

        int row = board_size.first - 1;
        while (board[row][col] != 0)
            row--;
        board[row][col] = turn;

        auto check_single = [&](int x, int y, int dx, int dy) -> int {
            if (!board[x][y] || x + dx * 3 >= board_size.first ||
                    y + dy * 3 >= board_size.second || y + dy * 3 < 0)
                return 0;
            for (int i = 1; i <= 3; i++)
                if (board[x + dx * i][y + dy * i] != board[x][y])
                    return 0;
            return board[x][y];
        };

        bool any_empty = false;
        for (int i = 0; i < board_size.first; i++)
            for (int j = 0; j < board_size.second; j++) {
                any_empty |= (board[i][j] == 0);
                int dx[4] = {0, 1, 1, 1}, dy[4] = {1, 0, 1, -1};
                for (int k = 0; k < 4; k++) {
                    int res = check_single(i, j, dx[k], dy[k]);
                    if (res == 1)
                        return status = P1_WIN;
                    else if (res == 2)
                        return status = P2_WIN;
                }
            }
        if (!any_empty)
            return status = TIE;
        turn = 3 - turn; // switch turn
        return ONGOING;
    }
    friend std::ostream& operator<<(std::ostream &ss, const Game &game) {
        ss << "\n";
        switch (game.status) {
            case P1_WIN: ss << "P1 Wins!\n"; break;
            case P2_WIN: ss << "P2 Wins!\n"; break;
            case TIE:    ss << "TIE!\n"; break;
            default:     ss << "Turn: P" << game.turn << "\n";
        }
        ss << "p1:O p2:X\n";
        for (int i = -1; i <= board_size.first; i++) {
            ss << (i == -1 || i == board_size.first ? "+" : "|");
            for (int j = 0; j < board_size.second; j++) {
                if (i == -1)
                    ss << j;
                else if (i == board_size.first)
                    ss << "-";
                else if (game.board[i][j] == 0)
                    ss << " ";
                else
                    ss << (game.board[i][j] == 1 ? "O" : "X");
            }
            ss << (i == -1 || i == board_size.first ? "+" : "|") << "\n";
        }
        ss.flush();
        return ss;
    }
};

class YP {
  public:
    uint32_t shiftstate;
    YP(int as_player, int seed) : side(as_player) {
      shiftstate = seed;
      for(int i=0; i<10; ++i)
        rng(); 
    }
    int rng() {
      shiftstate ^= shiftstate << 13; 
      shiftstate ^= shiftstate >> 17; 
      shiftstate ^= shiftstate << 5;
      return shiftstate % 5;
    }
    int calculate(std::vector<std::vector<int>> board) {
      int score = 0;
      bool win = false, lose = false;
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
          // std::cout << i << ' ' << j << std::endl;
          if (i + 3 < board.size()) {
            int a = 0, b = 0;
            for (int k = 0; k < 4; k++) {
              if (board[i + k][j] == side) {
                a++;
              }
              else if (board[i + k][j] == 3 - side) {
                b++;
              }
            }
            score += (rng() + 1) * a * a - (rng() + 1) * b * b;
            if (a == 4) {
              win = true;
            }
            if (b == 3 && a == 0) {
              lose = true;
            }
          }
          if (j + 3 < board[i].size()) {
            int a = 0, b = 0;
            for (int k = 0; k < 4; k++) {
              if (board[i][j + k] == side) {
                a++;
              }
              else if (board[i][j + k] == 3 - side) {
                b++;
              }
            }
            score += (rng() + 1) * a * a - (rng() + 1) * b * b;
            if (a == 4) {
              win = true;
            }
            if (b == 3 && a == 0) {
              lose = true;
            }
          }
          if (i + 3 < board.size() && j + 3 < board[i].size()) {
            int a = 0, b = 0;
            for (int k = 0; k < 4; k++) {
              if (board[i + k][j + k] == side) {
                a++;
              }
              else if (board[i + k][j + k] == 3 - side) {
                b++;
              }
            }
            score += (rng() + 1) * a * a - (rng() + 1) * b * b;
            if (a == 4) {
              win = true;
            }
            if (b == 3 && a == 0) {
              lose = true;
            }
          }
          if (i - 3 >= 0 && j + 3 < board[i].size()) {
            int a = 0, b = 0;
            for (int k = 0; k < 4; k++) {
              if (board[i - k][j + k] == side) {
                a++;
              }
              else if (board[i - k][j + k] == 3 - side) {
                b++;
              }
            }
            score += (rng() + 1) * a * a - (rng() + 1) * b * b;
            if (a == 4) {
              win = true;
            }
            if (b == 3 && a == 0) {
              lose = true;
            }
          }
        }
      }
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
          if (i + 4 < board.size()) {
            int a = 0, b = 0;
            for (int k = 0; k < 5; k++) {
              if (board[i + k][j] == side) {
                a++;
              }
              else if (board[i + k][j] == 3 - side) {
                b++;
              }
            }
            if (b > 1 && a == 0 && board[i][j] == 0 && board[i + 4][j] == 0) {
              lose = true;
            }
          }
          if (j + 4 < board[i].size()) {
            int a = 0, b = 0;
            for (int k = 0; k < 5; k++) {
              if (board[i][j + k] == side) {
                a++;
              }
              else if (board[i][j + k] == 3 - side) {
                b++;
              }
            }
            if (b > 1 && a == 0 && board[i][j] == 0 && board[i][j + 4] == 0) {
              lose = true;
            }
          }
          if (i + 4 < board.size() && j + 4 < board[i].size()) {
            int a = 0, b = 0;
            for (int k = 0; k < 5; k++) {
              if (board[i + k][j + k] == side) {
                a++;
              }
              else if (board[i + k][j + k] == 3 - side) {
                b++;
              }
            }
            if (b > 1 && a == 0 && board[i][j] == 0 && board[i + 4][j + 4] == 0) {
              lose = true;
            }
          }
          if (i - 4 >= 0 && j + 4 < board[i].size()) {
            int a = 0, b = 0;
            for (int k = 0; k < 5; k++) {
              if (board[i - k][j + k] == side) {
                a++;
              }
              else if (board[i - k][j + k] == 3 - side) {
                b++;
              }
            }
            if (b > 1 && a == 0 && board[i][j] == 0 && board[i - 4][j + 4] == 0) {
              lose = true;
            }
          }
        }
      }
      if (win) {
        return INT_MAX;
      }
      if (lose) {
        return -INT_MAX;
      }
      return score;
    }
    int operator()(const Game &game) {
        assert(game.turn == side && game.status == Game::ONGOING);
        int ans = 1, mx = -INT_MAX;
        for (int col = 0; col < 7; col++) {
          auto tmp = game.board;
          if (tmp[0][col] != 0) {
            continue;
          }
          int row = 5;
          while (tmp[row][col] != 0)
              row--;
          tmp[row][col] = side;
          int reward = calculate(tmp);
          if (reward > mx) {
            ans = col;
            mx = reward;
          }
        }
        while (game.board[0][ans] != 0) {
          ans = (ans + 1) % 7 ;
        }
        return ans;
    }
  private:
    int side;
};
} // namespace connect4_judge

int decide(int);

int main() {
    using connect4_judge::Game;
    using connect4_judge::YP;

    int seed;

#ifdef CONNECT4_INTERACTIVE
    std::cout << "Playing interactively!" << std::endl;
    std::cout << "Input the test number you want to play(number from 1 to 10)" << std::endl;
    std::cout.flush();
    if (!(std::cin >> seed) || seed < 1 || seed > 10) {
        std::cout << "Input test number Failed!" << std::endl;
        exit(1);
    }

    std::cout << "You are Player 1 (O), while the judge is Player 2 (X)." << std::endl;
    std::cout << "When it's your turn, please input a digit between 0 and 6 then press <ENTER>." << std::endl;
    #define CONNECT4_DEBUG // Always show game board when playing interacitvely
#else
    std::cout << "Playing automatically!" << std::endl;
    std::cout << "Input the test number you want to play(number from 1 to 10, 0 means that you want to test all the testdata together)" << std::endl;
    std::cout.flush();
    if (!(std::cin >> seed) || seed < 0 || seed > 10) {
        std::cout << "Input test number Failed!" << std::endl;
        exit(1);
    }

    int N_WIN = 0, N_TIE = 0, N_LOSE = 0;
#endif
    int n_games = (seed == 0)?(10):(1);

    long long total_time_us = 0;

    for (int round = 0; round < n_games; ++round) {
        Game game;
        if (n_games > 1) {
          seed = round+1;
        }
        YP yp(2, seed);
#ifdef CONNECT4_DEBUG
#ifndef CONNECT4_INTERACTIVE
        std::cerr << "=== Start of game " << round + 1 << " ===" << std::endl;
#endif
        std::cerr << game;
#endif
        int last_yp_move = -seed;
        while (game.status == Game::ONGOING) {
            Game::Result res = Game::INVALID_MOVE;
            int choice;
            if (game.turn == 1) {
#ifdef CONNECT4_INTERACTIVE
                std::cout << "Your move> ";
                std::cout.flush();
                if (!(std::cin >> choice)) {
                    std::cout << "Input move failed!" << std::endl;
                    exit(1);
                }
#else
                auto time_start = std::chrono::steady_clock::now();
                choice = decide(last_yp_move);
                auto time_end = std::chrono::steady_clock::now();
                total_time_us += std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start).count();
#endif
            }
            else {
                choice = last_yp_move = yp(game);
            }
            res = game.play(choice);
            if (res == Game::INVALID_MOVE) {
                std::cerr << "Invalid Move (move = " << choice << ") QQ..." << std::endl;
                exit(1);
            }
#ifdef CONNECT4_DEBUG
            std::cerr << game;
#endif
        }
#ifndef CONNECT4_INTERACTIVE
        if (game.status == Game::P1_WIN)
            N_WIN += 1;
        else if (game.status == Game::P2_WIN)
            N_LOSE += 1;
        else if (game.status == Game::TIE)
            N_TIE += 1;
#endif
    }

#ifndef CONNECT4_INTERACTIVE
    std::cout << "Your code finished in " << std::fixed << std::setprecision(3) << (double)total_time_us / 1e6 << " seconds (Not including YP's thinking time)." << std::endl;
    std::cout << "Done! Played " << n_games << " games." << std::endl;
    std::cout << "The result is " << N_WIN << " Win(s), " << N_TIE << " Tie(s), and " << N_LOSE << " Lose(s)." << std::endl;
#endif
}
