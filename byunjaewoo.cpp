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
    class PrefixSum {
    public:
        void init(vector<long long> V) {
            int N = V.size();
            A[0] = V[0];
            for(int i=1; i<N; i++) A[i] = A[i - 1] + V[i];
        }
        long long Query(int l, int r) {return A[r] - A[l - 1];}
    private:
        vector<long long> A;
    };
}
using namespace byunjaewoo;

int main() {
    return 0;
}
