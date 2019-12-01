#include <iostream>
using namespace std;

int main() {
    int total = 0, n;
    string in;
    while (getline(cin, in)) {
        n = stoi(in);
        while (n > 8) {
           total += (n / 3) - 2;
           n =  (n / 3) - 2;
        }
    }
    cout << total;
}