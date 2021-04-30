#include <stdio.h>
#include <vector>
#include <functional>
using namespace std;

namespace byunjaewoo {

    long long Factorial(int a) {
        if (a == 1) return 1;
        return a * Factorial(a - 1);
    }

    long long Factorial(int a, long long Mod) {
        if (a == 1) return 1;
        return ((long long)a * Factorial(a - 1)) % Mod;
    }

    long long Pow(int a, int x) {
        if (x == 0) return 1;
        if (x == 1) return a;
        long long res = Pow(a, x / 2);
        res *= res;
        if (x % 2) res *= a;
        return res;
    }

    long long Pow(int a, int x, int Mod) {
        if (x == 0) return 1;
        if (x == 1) return a;
        long long res = Pow(a, x / 2) % Mod;
        res = (res * res) % Mod;
        if (x % 2) res = (res * a) % Mod;
        return res;
    }

    class PrefixSum {
    public:
        void init(vector<long long> V) {
            int N = V.size();
            A[0] = V[0];
            for (int i = 1; i < N; i++) A[i] = A[i - 1] + V[i];
        }
        long long Query(int l, int r) { return A[r] - A[l - 1]; }
    private:
        vector<long long> A;
    };

    template<int N>
    class UnionFind {
    public:
        UnionFind() { G.resize(N, -1); }
        bool Union(int a, int b) {
            a = Find(a);
            b = Find(b);
            if (a == b) return 0;
            G[a] += G[b]; G[b] = a;
            return 1;
        }
        void Same(int a, int b) { return Find(a) == Find(b); }
        int Count(int x) { return -G[Find(x)]; }
    private:
        void Find(int x) {
            if (G[x] < 0) return x;
            return G[x] = Find(G[x]);
        }
        vector<int> G;
    };

    template<int N>
    class FenwickTree {
    public:
        FenwickTree() { Tree.resize(N, 0); }
        void Update(int k, long long v) {
            for (int i = k; i < N; i += i & -i) Tree[k] += v;
        }
        long long Query(int l, int r) { return Query(r) - Query(l - 1); }
        long long Query(int e) {
            long long res = 0;
            for (int i = e; i >= 0; i -= i & -i) res += Tree[i];
            return res;
        }
    private:
        vector<int> Tree;
    };

    template<char Op = '+', int N = (1 << 20)>
    class SegmentTree {
    public:
        SegmentTree() {
            S = (1 << (32 - __builtin_clz(N - 1)));
            Tree.resize(2 * S);
            if (Op == '+') {
                f = [](long long a, long long b) {return a + b; };
                z = 0;
            }
            else if (Op == '*') {
                f = [](long long a, long long b) {return a * b; };
                z = 1;
            }
            else if (Op == '|') {
                f = [](long long a, long long b) {return a | b; };
                z = 0;
            }
            else if (Op == '&') {
                f = [](long long a, long long b) {return a & b; };
                z = -1;
            }
            else if (Op == '^') {
                f = [](long long a, long long b) {return a ^ b; };
                z = 0;
            }
            fill(Tree.begin(), Tree.end(), z);
        }
        void Update(int k, long long v) {
            k += S - 1;
            Tree[k] = f(Tree[k], v);
            for (k >>= 1; k; k >>= 1)
                Tree[k] = f(Tree[k << 1], Tree[k << 1 | 1]);
        }
        void Change(int k, long long v) {
            k += S - 1;
            Tree[k] = v;
            for (k >>= 1; k; k >>= 1)
                Tree[k] = f(Tree[k << 1], Tree[k << 1 | 1]);
        }
        long long Query(int l, int r) {
            long long res = 0;
            for (l += S - 1, r += S - 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = f(res, Tree[l++]);
                if (!(r & 1)) res = f(res, Tree[r--]);
            }
            if (l == r) res = f(res, Tree[l]);
            return res;
        }
    private:
        int S; long long z;
        function<long long(long long, long long)> f;
        vector<long long> Tree;
    };
}
using namespace byunjaewoo;

int main() {
    return 0;
}