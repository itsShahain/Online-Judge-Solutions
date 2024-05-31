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

class UnionFind {
    // OOP style
private:
    vi p, rank, setSize; // vi p is the key part
    int numSets;

public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0); // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N; // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; } // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return; // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items
        if (rank[x] > rank[y]) swap(x, y); // keep x 'shorter' than y
        p[x] = y; // set x under y
        if (rank[x] == rank[y]) ++rank[y]; // optional speedup
        setSize[y] += setSize[x]; // combine set sizes at y
        --numSets; // a union reduces numSets
    }
};

void tc() {
}

void solve() {
    int N, M;
    int concoctable = 0;
    scanf("%d", &N);
    UnionFind uf(500001);
    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        vector<int> ingredients(M);
        int alreadyUsed = 0;
        unordered_set<int> cauldron;
        for (int j = 0; j < M; j++) {
            scanf("%d", &ingredients[j]);
            if (uf.sizeOfSet(ingredients[j]) != 1) {
                alreadyUsed++;
                cauldron.insert(uf.findSet(ingredients[j]));
            }
        }
        int tp = 0;
        for (auto it = cauldron.begin(); it != cauldron.end(); ++it) {
            tp += uf.sizeOfSet(*it);
        }

        if (tp == alreadyUsed) {
            // OK
            for (int j = 1; j < M; j++) {
                uf.unionSet(ingredients[j - 1], ingredients[j]);
            }
            concoctable++;
        }
    }

    printf("%d\n", concoctable);
}

// WOW: printf("%d%c", miss[i], " \n"[i==n-1]);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef FILE_IO
    setIO("test");
#endif
    solve();
    cout << flush;
}
