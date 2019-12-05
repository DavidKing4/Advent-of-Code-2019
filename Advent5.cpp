#include <iostream>
#include <vector>
using namespace std;


int modeToVal(int mode, int val, vector<int> xs) {
    return mode == 0  ? xs[val] : val;
}


int main() {
    string in;
    vector<int> xs;

    while (getline(cin, in, ',')) {
        if (in == "end") { // ADD ",end," to the int computer and then type input
            break;
        }
        xs.push_back(stoi(in));
    }

    int l = xs.size();
    int i = 0;

    while (i < l) {
        int op = xs[i] % 100;
        if (op == 99) {
            break;
        }

        int nounm = xs[i] % 1000 / 100;
        int noun = xs[i + 1];

        if (op == 3) {
            cin >> in;
            xs[noun] = stoi(in);
            i += 2;
            continue;
        }
        if (op == 4) {
            cout << xs[noun] << "\n";
            i += 2;
            continue;
        }

        int verbm = xs[i] % 10000 / 1000;
        int verb = xs[i + 2];

        if (op == 5) {
            if (modeToVal(nounm, noun, xs) != 0) {
                i = modeToVal(verbm, verb, xs);
            } else {
                i += 3;
            }
            continue;
        }
        if (op == 6){
            if (modeToVal(nounm, noun, xs) == 0) {
                i = modeToVal(verbm, verb, xs);
            } else {
                i += 3;
            }
            continue;
        }

        int addrm = xs[i] % 100000 / 10000;
        int addr = modeToVal(addrm, i + 3, xs);

        if (op == 1) {
            i += 4;
            xs[addr] = modeToVal(nounm, noun, xs) + modeToVal(verbm, verb, xs);
        } else if (op == 2) {
            i += 4;
            xs[addr] = modeToVal(nounm, noun, xs) * modeToVal(verbm, verb, xs);
        } else if (op == 7){
            if (modeToVal(nounm, noun, xs) < modeToVal(verbm, verb, xs)){
                xs[addr] = 1;
            }else {
                xs[addr] = 0;
            }
            i += 4;
        } else if (op == 8){
            if (modeToVal(nounm, noun, xs) == modeToVal(verbm, verb, xs)){
                xs[addr] = 1;
            } else {
                xs[addr] = 0;
            }
            i += 4;
        } else {
            cout << op << " error\n";
            break;
        }
    }
}