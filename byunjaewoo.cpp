#include <stdio.h>

namespace byunjaewoo {
    long long Factorial (int a) {
        if(a==1) return 1;
        return a * Factorial(a - 1);
    }
}
using namespace byunjaewoo;

int main() {
    return 0;
}
