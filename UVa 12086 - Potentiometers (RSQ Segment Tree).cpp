#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define FILE_IO

typedef long long ll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

typedef vector<int> vi;

class SegmentTree {
    // OOP style
private:
    int n; // n = (int)A.size()
    vi A, st, lazy; // the arrays

    int l(int p) { return p << 1; } // go to left child
    int r(int p) { return (p << 1) + 1; } // go to right child

    int conquer(int a, int b) {
        return a + b; // RSQ
    }

    void build(int p, int L, int R) {
        // O(n)
        if (L == R)
            st[p] = A[L]; // base case
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    void propagate(int p, int L, int R) {
        if (lazy[p] != 0) {
            // has a lazy flag
            st[p] += lazy[p] * (R - L + 1);
            if (L != R) {
                // not a leaf
                lazy[l(p)] += lazy[p]; // propagate downwards
                lazy[r(p)] += lazy[p];
            } else // L == R, a single index
                A[L] += lazy[p]; // time to update this
            lazy[p] = 0; // erase lazy flag
        }
    }

    int RSQ(int p, int L, int R, int i, int j) {
        // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > R || j < L) return 0; // infeasible
        if ((L >= i) && (R <= j)) return st[p]; // found the segment
        int m = (L + R) / 2;
        return conquer(RSQ(l(p), L, m, i, j),
                       RSQ(r(p), m + 1, R, i, j));
    }

    void update(int p, int L, int R, int i, int j, int val) {
        // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > R || j < L) return;
        if ((L >= i) && (R <= j)) {
            // found the segment
            lazy[p] = val; // update this
            propagate(p, L, R); // lazy propagation
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, j, val);
            update(r(p), m + 1, R, i, j, val);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

public:
    SegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, 0) {
    }

    SegmentTree(const vi &initialA) : SegmentTree((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int RSQ(int i, int j) { return RSQ(1, 0, n - 1, i, j); }
};


void tc(int N) {
    vector<int> resistor(N);
    for (int i = 0; i < N; i++) {
        cin >> resistor[i];
    }

    SegmentTree st(resistor);

    int x, y, r;
    string command;
    while (cin >> command, command[0] != 'E') {
        if (command[0] == 'S') {
            cin >> x >> r;
            st.update(x - 1, x - 1, r - resistor[x - 1]);
            resistor[x - 1] = r;
        } else {
            cin >> x >> y;
            cout << st.RSQ(x - 1, y - 1) << '\n';
        }
    }
}

void solve() {
    int N;
    int TC = 1;
    while (cin >> N, N != 0) {
        if (TC != 1) printf("\n");
        printf("Case %d:\n", TC);
        tc(N);
        ++TC;
    }
}

// WOW: printf("%d%c", miss[i], " \n"[i==n-1]);

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
#ifdef FILE_IO
    setIO("test");
#endif
    solve();
    cout << flush;
}
