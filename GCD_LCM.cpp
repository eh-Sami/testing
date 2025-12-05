#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    if(!a or !b) return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= shift;
    while(b) {
        b >>= __builtin_ctz(b);
        if(a > b) {
            swap(a, b);
        }
        b -= a;
    }
    a <<= shift;
    return a;
}

int LCM(int a, int b) {
    return a / GCD(a, b) * b;
}

int main() {
    int a = GCD(4, 6);
    cout << a << endl;
    a = LCM(4, 6);
    cout << a;
}