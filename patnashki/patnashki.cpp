#include <iostream>
#include<math.h>
using namespace std;
int a[4][4];
void printM() {
    for (int i = 0;i < 4;++i) {
        for (int j = 0;j < 4;++j) {
            if (a[i][j] == 0) {
                cout << "*  ";
            }
            else {
                if (a[i][j] - a[i][j] % 10 > 0) {
                    cout << a[i][j] << ' ';
                }
                else {
                    cout << a[i][j] << "  ";
                }
            }
        }
        cout << endl;
    }
}

bool upM() {
    for (int i = 0;i < 4;++i) {
        for (int j = 0;j < 4;++j) {
            if (a[i][j] == 0) {
                if (i == 0) {
                    return 1;
                }
                else {
                    a[i][j] = a[i - 1][j];
                    a[i - 1][j] = 0;
                    printM();
                    return 0;
                }
            }
        }
    }
}
bool downM() {
    for (int i = 0;i < 4;++i) {
        for (int j = 0;j < 4;++j) {
            if (a[i][j] == 0) {
                if (i == 3) {
                    return 1;
                }
                else {
                    a[i][j] = a[i + 1][j];
                    a[i + 1][j] = 0;
                    printM();
                    return 0;
                }
            }
        }
    }
}
bool leftM() {
    for (int i = 0;i < 4;++i) {
        for (int j = 0;j < 4;++j) {
            if (a[i][j] == 0) {
                if (j == 0) {
                    return 1;
                }
                else {
                    a[i][j] = a[i][j - 1];
                    a[i][j - 1] = 0;
                    printM();
                    return 0;
                }
            }
        }
    }
}
bool rightM() {
    for (int i = 0;i < 4;++i) {
        for (int j = 0;j < 4;++j) {
            if (a[i][j] == 0) {
                if (j == 3) {
                    return 1;
                }
                else {
                    a[i][j] = a[i][j + 1];
                    a[i][j + 1] = 0;
                    printM();
                    return 0;
                }
            }
        }
    }
}

int main() {
    cout << "                Игра пятнашки" << endl;
    cout << "Правила:" << endl;
    cout << "Чтобы победить надо выставить все числа в порядке возрастания по рядам\n" << "пользуясь командами up down left и right которые вызываются цифрами\n" << "2 8 4 и 6 соответственно если же вы считаете что устали всегда\n" << "можно сдаться нажав на цифру 5 а потом на кнопку enter." << endl;
    int b, c = 0, e, r, P = 0, m, G = 1;
    bool M = 0;
    for (int i = 0;i < 4;++i) {
        for (int j = 0;j < 4;++j) {
            a[i][j] = 16;
        }
    }
    for (e = 0;e < 4;++e) {
        for (r = 0;r < 4;++r) {
            b = rand() % 16;
            for (int q = 0;q < 4;++q) {
                for (int w = 0;w < 4;++w) {
                    if (a[q][w] == b) {
                        if (r == 0) {
                            --e;
                            r = 3;
                        }
                        else {
                            --r;
                        }
                        ++c;
                        break;
                        break;
                    }
                }
            }
            if (c == 0) {
                a[e][r] = b;
            }
            c = 0;
        }
    }
    printM();
    while (P == 0) {
        cin >> m;
        if (m == 2) {
            M = downM();
        }
        else if (m == 4) {
            M = leftM();
        }
        else if (m == 6) {
            M = rightM();
        }
        else if (m == 8) {
            M = upM();
        }
        else if (m == 5) {
            P = 2;
        }
        if (M == 1) {
            cout << "ERROR you can not do this" << endl;
            M = 0;
        }
        for (int i = 0;i < 4;++i) {
            for (int j = 0;j < 4;++j) {
                if (G == 0) {
                    break;
                    break;
                }
                if (G == a[i][j]) {
                    ++G;
                    G %= 16;
                }
                else {
                    G = 1;
                    break;
                    break;
                }
            }
        }
        if (G == 0) {
            P = 1;
        }
    }
    if (P == 1) {
        cout << "You win" << endl;
    }
    else if (P == 2) {
        cout << "You lose" << endl;
    }
    return 0;
}