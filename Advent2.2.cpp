#include <iostream>
#include <vector>
using namespace std;

int main() {
    string in;
    vector<int> xs;

    while (getline(cin, in, ',')) {
        xs.push_back(stoi(in));
    }

    int l = xs.size();

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++) {
            vector<int> ys = xs;
            ys[1] = i;
            ys[2] = j;
            for (int k = 0; k < l; k += 4) {
                int op = ys[k];
                int noun = ys[k + 1];
                int verb = ys[k + 2];
                int addr = ys[k + 3];
                if (addr >= l) {
                    break;
                }
                if (op == 0) {
                    continue;
                } else if (op == 1) {
                    ys[addr] = ys[noun] + ys[verb];
                } else if (op == 2) {
                    ys[addr] = ys[noun] * ys[verb];
                } else {
                    break;
                }
            }
            if (ys[0] == 19690720) {
                cout << 100 * ys[1] + ys[2];
                return 0;
            }
        }
    }
}