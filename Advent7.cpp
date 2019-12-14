#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


class IntCode {
    private:
        vector<int> tape;
        deque<int> input;
        int l;
        int p;
        bool halted = false;

    public:
        IntCode(vector<int> t, deque<int> in = {0}, int s = 0){
            tape = t;
            input = in;
            p = s;
            l = t.size();
        }

        bool isHalted(){
            return halted;
        }

        void addInput(vector<int> in){
            input.insert(input.end(), in.begin(), in.end());
        }

        vector<int> run(){
            vector<int> printed;
            while (p < l) {
                int op = tape[p] % 100;
                if (op == 99) {
                    halted = true;
                    return printed;
                }
                int nounm = tape[p] % 1000 / 100;
                int noun = tape[p + 1];
                if (op == 3) {
                    if (input.empty())
                        return printed;
                    tape[noun] = input.front();
                    input.pop_front();
                    p += 2;
                    continue;
                } else if (op == 4) {
                    printed.push_back(tape[noun]);
                    p += 2;
                    continue;
                }
                int verbm = tape[p] % 10000 / 1000;
                int verb = tape[p + 2];
                if (op == 5) {
                    if (mtov(nounm, noun, tape) != 0) {
                        p = mtov(verbm, verb, tape);
                    } else {
                        p += 3;
                    }
                    continue;
                } else if (op == 6) {
                    if (mtov(nounm, noun, tape) == 0) {
                        p = mtov(verbm, verb, tape);
                    } else {
                        p += 3;
                    }
                    continue;
                }
                int addrm = tape[p] % 100000 / 10000;
                int addr = mtov(addrm, p + 3, tape);
                if (op == 1) {
                    p += 4;
                    tape[addr] = mtov(nounm, noun, tape) + mtov(verbm, verb, tape);
                } else if (op == 2) {
                    p += 4;
                    tape[addr] = mtov(nounm, noun, tape) * mtov(verbm, verb, tape);
                } else if (op == 7){
                    if (mtov(nounm, noun, tape) < mtov(verbm, verb, tape)){
                        tape[addr] = 1;
                    }else {
                        tape[addr] = 0;
                    }
                    p += 4;
                } else if (op == 8){
                    if (mtov(nounm, noun, tape) == mtov(verbm, verb, tape)){
                        tape[addr] = 1;
                    } else {
                        tape[addr] = 0;
                    }
                    p += 4;
                } else {
                    cout << op << " error\n";
                    cout << p << "\n";
                    return printed;
                }
            }
            return printed;
        }

    private:
        int mtov(int mode, int val, vector<int> tape) {
            return mode == 0  ? tape[val] : val;
        }
};


int main() {
    string in;
    vector<int> xs;

    while (getline(cin, in, ',')) {
        if (in == "end") { 
            break;
        }
        xs.push_back(stoi(in));
    }

    vector<int> v1 = {0, 1, 2, 3, 4};
    int biggest = 0;
    do {
        vector<int> t;
        IntCode ampA(xs, {v1[0], 0}, 0); 
        t = ampA.run();
        IntCode ampB(xs, {v1[1]}, 0);
        ampB.addInput(t);
        t = ampB.run();
        IntCode ampC(xs, {v1[2]}, 0);
        ampC.addInput(t);
        t = ampC.run();
        IntCode ampD(xs, {v1[3]}, 0);
        ampD.addInput(t);
        t = ampD.run();
        IntCode ampE(xs, {v1[4]}, 0);
        ampE.addInput(t);
        t = ampE.run();
        if (t.back() > biggest) {
            biggest = t.back();
        }
    } while (next_permutation(v1.begin(), v1.end()));
    cout << biggest << "\n";

    vector<int> v2 = {5, 6, 7, 8, 9};
    biggest = 0;
    do {
        vector<int> t;
        IntCode ampA(xs, {v2[0], 0}, 0);
        t = ampA.run();
        IntCode ampB(xs, {v2[1]}, 0);
        ampB.addInput(t);
        t = ampB.run();
        IntCode ampC(xs, {v2[2]}, 0);
        ampC.addInput(t);
        t = ampC.run();
        IntCode ampD(xs, {v2[3]}, 0);
        ampD.addInput(t);
        t = ampD.run();
        IntCode ampE(xs, {v2[4]}, 0);
        ampE.addInput(t);
        t = ampE.run();

        while (true) {
            if (ampA.isHalted() || ampB.isHalted() || ampC.isHalted() || ampD.isHalted() || ampE.isHalted()) {
                while (not ampE.isHalted())
                    t = ampE.run();
                break;
            }
            ampA.addInput(t);
            t = ampA.run();
            ampB.addInput(t);
            t = ampB.run();
            ampC.addInput(t);
            t = ampC.run();
            ampD.addInput(t);
            t = ampD.run();
            ampE.addInput(t);
            t = ampE.run();
        }
        if (t.back() > biggest) {
            biggest = t.back();
        }
    } while (next_permutation(v2.begin(), v2.end()));
    cout << biggest << "\n";
}