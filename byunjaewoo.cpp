#include <stdio.h>

namespace byunjaewoo {
    long long Factorial (int a) {
        if(a==1) return 1;
        return a * Factorial(a - 1);
    }
    long long Pow(int a, int x) {
        if(x==0) return 1;
        if(x==1) return a;
        long long res = Pow(a, x/2);
        res *= res;
        if(x % 2) res *= a;
        return res;
    }
    long long Pow(int a, int x, int Mod) {
        if(x==0) return 1;
        if(x==1) return a;
        long long res = Pow(a, x / 2) % Mod;
        res = (res * res) % Mod;
        if(x % 2) res = (res * a) % Mod;
        return res;
    }
}
using namespace byunjaewoo;

int main() {
    return 0;
}
