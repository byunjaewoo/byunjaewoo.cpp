#include <stdio.h>
#include <vector>
using namespace std;

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

    template<int N>
    class UnionFind {
    public:
        UnionFind() {G.resize(N, -1);}
        bool Union(int a, int b) {
            a = Find(a);
            b = Find(b);
            if(a == b) return 0;
            G[a] += G[b]; G[b] = a;
            return 1;
        }
        void Same(int a, int b) {return Find(a) == Find(b);}
        int Count(int x) {return -G[Find(x)];}
    private:
        void Find(int x) {
            if(G[x] < 0) return x;
            return G[x] = Find(G[x]);
        }
        vector<int> G;
    };

    template<int N>
    class FenwickTree {
    public:
        FenwickTree() {Tree.resize(N, 0);}
        void Update(int k, long long v) {
            for(int i=k; i<N; i+=i&-i) Tree[k] += v;
        }
        long long Query(int l, int r) {return Query(r) - Query(l - 1);}
        long long Query(int e) {
            long long res = 0;
            for(int i=e; i>=0; i-=i&-i) res += Tree[i];
            return res;
        }
    private:
        vector<int> Tree;
    };
}
using namespace byunjaewoo;

int main() {
    return 0;
}
