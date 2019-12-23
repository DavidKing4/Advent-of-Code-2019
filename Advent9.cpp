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
        int rb;
        bool halted = false;

    public:
        IntCode(vector<int> t, deque<int> in = {0}, int s = 0, int relative_base = 0, int buffer = 1000){
            tape = t;
            input = in;
            p = s;
            l = t.size();
            for (int i = 0; i < buffer; i++) {
                tape.push_back(0);
            }
            rb = relative_base;
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
                } else if (op == 9) {
                    rb += noun;
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
            if (mode == 2)
                return tape[val - rb];
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

    IntCode comp(xs, {}, 0, 0, 0);
    vector<int> v = comp.run();

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
}