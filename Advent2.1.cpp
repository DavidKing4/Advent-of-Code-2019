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
    xs[1] = 12;
    xs[2] = 2;

    for (int i = 0; i < l; i += 4) {
        int op = xs[i];
        int noun = xs[i + 1];
        int verb = xs[i + 2];
        int addr = xs[i + 3];
        if (op == 0) {
            continue;
        } else if (op == 1) {
            xs[addr] = xs[noun] + xs[verb];
        } else if (op == 2) {
            xs[addr] = xs[noun] * xs[verb];
        } else {
            break;
        }
    }
    cout << xs[0];
}