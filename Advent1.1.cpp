#include <iostream>
using namespace std;

int main() {
    int total = 0;
    string n;
    while (getline(cin, n)) {
        total += (stoi(n) / 3) - 2;
    }
    cout << total;
}