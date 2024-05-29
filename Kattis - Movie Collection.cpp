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

#define LSOne(S) ((S) & -(S))
vector<int> fenwick;

ll rsq(int i) {
    ll sum = 0LL;
    for(; i; i -= LSOne(i)) {
        sum += fenwick[i];
    }
    return sum;
}

void add(int i, int x) {
    for(; i < fenwick.size(); i += LSOne(i)) {
        fenwick[i] += x;
    }
}

void build() {
    for(int i = 1; i < fenwick.size(); i++) {
        int parent = i + LSOne(i);
        if(parent < fenwick.size()) fenwick[parent] += fenwick[i];
    }
}

void tc() {
    int m, r;
    scanf("%d %d", &m, &r);
    vector<int> lastPolled(m + 1, 0);
    fenwick = vector<int>(m + r + 1, 0);

    for(int i = 1; i <= m; i++) {
        fenwick[m + 1 - i] = 1;
        lastPolled[m + 1 - i] = i;
    }

    build();

    int movie;
    for(int i = m + 1; i <= m + r; i++) {
        scanf("%d", &movie);
        printf("%lld ", rsq(i) - rsq(lastPolled[movie]));
        add(i, 1);
        add(lastPolled[movie], -1);
        lastPolled[movie] = i;
    }
    printf("\n");
}

void solve() {
    int TC;
    scanf("%d", &TC);
    while(TC--) tc();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef FILE_IO
    setIO("test");
#endif
    solve();
    cout << flush;
}
