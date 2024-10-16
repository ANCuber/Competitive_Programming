#include <iostream>
#include <cmath>
using namespace std;

int DigitNumbers[10][10][10] = {{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
},{
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
},{
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
},{
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
},{
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
},{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
},{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
},{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
},{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
},{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
}};

int Brain[10][10];
// our brain can dream about 10 x 10 image

float LinkWeights[10][10][10][10];
// LinkWeights[y][x][y2][x2] is high
// if [y][x] and [y2][x2] should be the same
// low if they should be different

void WatchImage(int Image[10][10]) {
    /*
        Watch the image and adjust the weights  
        Use four layers of loops to iterate through
        coordinates x, y, x2, y2
        Consider the four pixels
        Brain[y][x], Brain[y2][x2], Image[y][x], Image[y2][x2];
        If these two pixel are different in the image
        but our brain think they are,
        decrease the weight LinkWeights[y][x][y2][x2] by 0.001.
        If these two pixel are the same in the image
        but our brain think they are different,
        increase the weight by 0.001.
    */
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                for (int l = 0; l < 10; ++l) {
                    if (Brain[i][j] == Brain[k][l] && Image[i][j] != Image[k][l]) LinkWeights[i][j][k][l] -= 0.005;
                    if (Brain[i][j] != Brain[k][l] && Image[i][j] == Image[k][l]) LinkWeights[i][j][k][l] += 0.005;
                }
            }
        }
    }
}

void DayDream(int seconds) {
    /*
        Every second, we pick a random pixel Brain[y][x]
        and calculate the total influence of all other pixels
        by iterating through x2, y2
        If Brain[y2][x2] is 1, add LinkWeights[y][x][y2][x2] to the influence
        If Brain[y2][x2] is 0, subtract LinkWeights[y][x][y2][x2] from the influence
        Let Brain[y][x] be 1 with probability 1 / (1 + exp(-influence)), zero otherwise
    */
    for (int i = 0; i < seconds; ++i) {
        int y = rand()%10, x = rand()%10;
        double influence = 0;
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (j == y && k == x) continue;
                Brain[j][k]?(influence += LinkWeights[y][x][j][k]):(influence -= LinkWeights[y][x][j][k]);
            }
        }
        ((double)rand()/(RAND_MAX*1.0) <= (1.0/(1.0+exp(-influence))))?(Brain[y][x] = 1):(Brain[y][x] = 0);
    }
}

int main() {
    srand(time(NULL));
    int MRI[10][120];

    for (int i = 0; i < 10; ++i) 
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 10; ++k) 
                for (int l = 0; l < 10; ++l)
                    LinkWeights[i][j][k][l] = 0.0;

    for (int day = 0; day < 1000; day++){
        /*
            Watch digit 0 and dream for 10000 seconds
            Watch digit 1 and dream for 10000 seconds
        */
        for (int i = 0; i < 10; ++i) {
            WatchImage(DigitNumbers[i]);
            DayDream(5000);
        }
        // Take a MRI scan of the brain
        for (int y = 0; y < 10; y++) {
            MRI[y][12 * (day%10)] = 0;
            for (int x = 0; x < 10; x++) {
                MRI[y][12 * (day%10) + x + 1] = Brain[y][x];
            }
            MRI[y][12 * (day%10) + 11] = 1;
        }
        // print if we have 10 MRI scans
        if (day % 10 == 9) {
            cout << "day" << day << endl;
            for (int y = 0; y < 10; y++) {
                for (int x = 0; x < 120; x++) {
                    cout << (MRI[y][x] ? '#' : ' ');
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}
