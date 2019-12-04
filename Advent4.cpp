#include <iostream>
#include <array>
#include <math.h>
#include <cmath>
using namespace std;

int main() {
    array<int, 2> b;
    int i = 0;
    string s;
    while (getline(cin, s, '-')) {
        b[i] = stoi(s);
        i++;
    }
    int total1 = 0, total2 = 0;
    for (i = b[0]; i <= b[1]; i++) {
        bool eq1 = false, eq2 = false, broke = false;
        int last = -1;
        int d1 = i % 10;
        int d2 = i % 100 / 10;
        int next = i % 1000 / 100;
        int lg = log10(i) / 1;
        for (int j = 3; j < lg + 3; j++) {
            if (d1 < d2) {
                broke = true;
                break;
            }
            if (d1 == d2) {
                eq1 = true;
                if ((j == 3 || last != d1) && d2 != next) {
                    eq2 = true;
                }
            }
            last = d1;
            d1 = d2;
            d2 = next;
            int t = ceil(pow(10, (j + 1)));
            next = (i % t) / ceil(pow(10, j));
        }
        if (!broke && d1 >= d2) {
            if (eq1 || d1 == d2) {
                total1++;
                if (eq2 || (last != d1 && d2 != next)) {
                    total2++;
                }
            }
        }
    }
    cout << total1 << "\t";
    cout << total2 << "\n";
}