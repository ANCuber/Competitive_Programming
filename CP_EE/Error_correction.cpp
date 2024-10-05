#include<iostream>
#include<cmath>
using namespace std;

int GF256mul(int a, int b) {
    a = (a % 256 + 256) % 256;
    b = (b % 256 + 256) % 256;
    if (a*b == 0) { return 0; }
    int c = (a + b) % 255;
    if (c == 0) { return 255; }
    return c;
}

int Zech_table[255] = {
    0, 25, 50, 223, 100, 138, 191, 112, 200, 120, 21, 245, 127, 99, 224,
    33, 145, 68, 240, 92, 42, 10, 235, 196, 254, 1, 198, 104, 193, 181,
    66, 45, 35, 15, 136, 32, 225, 179, 184, 106, 84, 157, 20, 121, 215,
    31, 137, 101, 253, 197, 2, 238, 141, 147, 208, 63, 131, 83, 107, 82,
    132, 186, 90, 55, 70, 162, 30, 216, 17, 130, 64, 109, 195, 236, 103,
    199, 113, 228, 212, 174, 168, 160, 59, 57, 40, 170, 242, 167, 175,
    203, 62, 209, 19, 158, 202, 176, 251, 190, 139, 13, 4, 47, 221, 74,
    27, 248, 39, 58, 161, 71, 126, 246, 7, 76, 166, 243, 214, 122, 164,
    153, 9, 43, 117, 183, 180, 194, 110, 12, 140, 239, 69, 56, 60, 250,
    177, 144, 34, 46, 5, 98, 128, 52, 218, 150, 135, 16, 217, 53, 206,
    188, 143, 178, 226, 119, 201, 159, 169, 41, 93, 155, 81, 108, 65,
    182, 118, 227, 114, 87, 80, 156, 85, 211, 229, 232, 79, 88, 95, 134,
    151, 37, 124, 29, 163, 123, 38, 249, 61, 204, 149, 219, 97, 6, 247,
    28, 125, 72, 23, 49, 26, 75, 8, 154, 94, 89, 187, 207, 148, 205, 54,
    91, 241, 171, 78, 233, 116, 44, 67, 146, 142, 189, 252, 102, 237, 3,
    14, 36, 152, 165, 77, 172, 231, 230, 173, 213, 244, 22, 73, 222, 51,
    129, 18, 210, 86, 115, 234, 11, 111, 192, 105, 185, 133, 96, 220,
    48, 24
};

int GF256add1(int a) {
    a = (a % 256 + 256) % 256;
    if (a == 0) { return 255; }
    if (a == 255) { return 0; }
    return Zech_table[a];
}

int GF256add(int a, int b) {
    a = (a % 256 + 256) % 256;
    b = (b % 256 + 256) % 256;
    if (a == b) { return 0; }
    if (a > b) { a ^= b ^= a ^= b; }
    if (a == 0) { return b; }
    return GF256mul(a, GF256add1(b - a));
}
void insert_noise(int codeword[5]) {
    int id = (rand() ^ rand()) % 5, mdf = (rand() ^ rand()) % 256;
    codeword[id] = mdf;
}

void Encode(int message[3], int codeword[5]) {
    for (int i = 0; i < 5; ++i) 
        codeword[i] = GF256add(GF256add(GF256mul(i,message[1]),GF256mul(GF256mul(i,i),message[2])),message[0]);
}

void Encode2(int message[3], int codeword[5]) {
    auto O=message;auto OO=codeword;auto O0=&rand;auto O1=&GF256add;auto
    Ol=&GF256mul;int l1=O[1],l=O[1026&106],ll=O0()%250+3,o=O0()&1111;OO[
    false]=(0xa&5)[O];true[OO]=O1(O1(0[O],Ol(O1(l1,Ol(1,O1(l,o))),1)),Ol
    (o,2));OO[1<<1]=Ol(O1(Ol(2,O1(Ol(l1,ll),Ol(55-'5',Ol(l,ll)))),Ol(OO[
    O1(l,l)],ll)),0xff^ll);3[OO]=O1(O1(Ol(Ol(255,l),6),Ol(l1,3)),O[2^2])
    ;4[OO]=O1(Ol(O1(4,3),l1),O1(OO[0b11],Ol(Ol(O1(3,4),l),O1(18/5,Ol(3,1
    )))));
}

void Decode(int codeword[5], int message[3]) {
    int tmp[5];
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            for (int k = 0; k < 256; ++k) {
                int cnt = 0;
                int cur[3] = {i,j,k};
                Encode(cur,tmp);
                for (int l = 0; l < 5; ++l) cnt += (tmp[l] != codeword[l]);
                if (cnt <= 1) {
                    message[0] = i;
                    message[1] = j;
                    message[2] = k;
                    return;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));//added by me
    cout << "Reed Solomon Example" << endl;
    int message[3];
    message[0] = rand() % 256;
    message[1] = rand() % 256;
    message[2] = rand() % 256;
    cout << "Random Message: " << message[0] << " " << message[1] << " " << message[2] << endl;
    int codeword[5];
    Encode(message, codeword);
    cout << "Codeword: " << codeword[0] << " " << codeword[1] << " " << codeword[2] << " " << codeword[3] << " " << codeword[4] << endl;
    insert_noise(codeword);
    cout << "Corrupted word: " << codeword[0] << " " << codeword[1] << " " << codeword[2] << " " << codeword[3] << " " << codeword[4] << endl;
    Decode(codeword, message);
    cout << "Decoded Message: " << message[0] << " " << message[1] << " " << message[2] << endl;
    cout << "Does the guess match the original message?" << endl;
}
