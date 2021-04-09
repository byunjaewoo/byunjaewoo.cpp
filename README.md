# TODO:
- Geometry - point, line
- Dijkstra
- Bellman Ford
- Floyd Warshall
- Minimum Spanning Tree
- Topological Sort
- Eulerian Trail
- Strongly Connected Component
- Articulation Point
- Network Flow
- Maximum Bipartite Matching
- Lowest Common Ancestor
- Lazy Propagation
- Convex Hull
- KMP
- Persistent Segment Tree
- Heavy - Light Decomposition
- Segment Tree 2D
- Dynamic Segment Tree
- Dynamic Segment Tree 2D
- BigInteger

# How To Use?

## Factorial
#### Explanation
* Factorial(a) : returns a!.
* Factorial(a, Mod) : returns a! mod Mod.
#### Constraints
* 0 ≤ a ≤ 2^31 - 1
* 0 ≤ Mod ≤ 2^63 - 1
#### Time Complexity
* Best : O(a)
* Worst : O(a)

## Fast Power
#### Explanation
* Pow(a, b) : returns a ^ b.
* Pow(a, b, Mod) : returns a ^ b mod Mod.
#### Constraints
* 0 ≤ a, b, Mod ≤ 2^63 - 1
#### Time Complexity
* Best : O(log b)
* Worst : O(log b)

## Prefix Sum
#### Explanation
* PrefixSum
* init(vector<long long> A) : init Prefix Sum into A
* Query(l, r) : returns sum from lth value to rth value
#### Constraints
* let N size of A
* 1 ≤ N ≤ 2^31 - 1
#### Time Complexity
* init
* Best : O(N)
* Worst : O(N)
* Query
* Best : O(1)
* Worst : O(1)

## Union Find
#### Explanation
* UnionFind<N>
* Union(a, b) : Merge a, b and returns if a, b is in the different group
* Same(a, b) : returns if a, b is in the same group
* Count(x) : returns size of x's group.
#### Constraints
* 1 ≤ N ≤ 2^31 - 1
#### Time Complexity
* Union, Same, Count
* Best : O(log* N)
* Worst : O(log* N)

## Fenwick Tree
#### Explanation
* FenwickTree<N>
* Update(k, v) : add v in kth value.
* Query(l, r) : returns sum of lth value to rth value.
#### Constraints
* 1 ≤ N ≤ 2^31 - 1
* 1 ≤ l, r, k ≤ N
* -2^63 ≤ v ≤ 2^63-1
#### Time Complexity
* Update, Query
* Best : O(log N)
* Worst : O(log N)


## Segment Tree
#### Explanation
* SegmentTree<Op, N>
* Update(k, v) : Update kth value with v
* Change(k, v) : Change kth value with v
* Query(l, r) : returns query from l to r
#### Contraints
* Op should be one from '+'(plus), '*'(multiply), '|'(Bitwise OR), '&'(Bitwise AND), '|'(Bitwise OR)
* 1 ≤ N ≤ 2^31 - 1
* 1 ≤ l, r, k ≤ N
* -2^63 ≤ v ≤ 2^63-1
#### Time Complexity
* Update, Change, Query
* Best : O(log N)
* Worst : O(log N)
