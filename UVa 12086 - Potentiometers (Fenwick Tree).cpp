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
vector<ll> fenwick;

void add(int x, ll r) {
    for(; x < fenwick.size(); x += LSOne(x)) {
        fenwick[x] += r;
    }
}

ll rsq(int x) {
    ll sum = 0LL;
    for(; x; x -= LSOne(x)) {
        sum += fenwick[x];
    }
    return sum;
}

void build() {
    for(int i = 1; i < fenwick.size(); i++) {
        int parent = i + LSOne(i);
        if(parent < fenwick.size()) fenwick[parent] += fenwick[i];
    }
}

void tc(int N) {
    fenwick = vector<ll>(N + 1);
    vector<ll> resistor(N + 1);
    for(int i = 0; i < N; i++) {
        cin >> fenwick[i + 1];
        resistor[i + 1] = fenwick[i + 1];
    }

    build();

    int x, y; ll r;
    string command;
    while(cin >> command, command[0] != 'E') {
        if(command[0] == 'S') {
            cin >> x >> r;
            add(x, r - resistor[x]);
            resistor[x] = r;
        } else {
            cin >> x >> y;
            cout << rsq(y) - rsq(x - 1) << '\n';
        }
    }
}

void solve() {
    int N;
    int TC = 1;
    while(cin >> N, N != 0) {
        if(TC != 1) printf("\n");
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
