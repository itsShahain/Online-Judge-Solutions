#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define FILE_IO
// #define RUNTIME

typedef long long ll;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

void tc() {
    int N;
    ll temp, sum = 0LL;
    ost rb;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        rb.insert({temp, i});
        if (i & 1) {
            sum += rb.find_by_order(i / 2)->first;
        } else {
            ll x = rb.find_by_order(i / 2)->first;
            ll y = rb.find_by_order(i / 2 - 1)->first;
            sum += (x + y) / 2LL;
        }
    }
    cout << sum << '\n';
}

void solve() {
    int TC;
    cin >> TC;
    while (TC--) {
        tc();
    }
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
