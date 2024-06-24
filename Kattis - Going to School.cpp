#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define FILE_IO

typedef long long ll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; // for every manhattan grid!

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

void tc() {
}

void solve() {
    vector<char> directions;
    char c;
    while (cin >> c) directions.push_back(c); // Read only valid characters
    int n = directions.size();
    vector<pair<ll, ll> > memo(n + 1, {INT_MAX, INT_MAX});

    memo[n].second = 0; // end at north
    memo[n].first = 1; // end at south

    for (int i = n - 1; i >= 0; i--) {
        for (int d = 0; d <= 1; d++) {
            if (d == 1) {  // North
                if (directions[i] == 'N') {
                    memo[i].second = min(1 + memo[i + 1].second, 1 + memo[i + 1].first);
                } else if (directions[i] == 'S') {
                    memo[i].second = min(memo[i + 1].second, 2 + memo[i + 1].first);
                } else {
                    memo[i].second = min(1 + memo[i + 1].second, 2 + memo[i + 1].first);
                }
            } else {
                if (directions[i] == 'N') {
                    memo[i].first = min(memo[i + 1].first, 2 + memo[i + 1].second);
                } else if (directions[i] == 'S') {
                    memo[i].first = min(1 + memo[i + 1].first, 1 + memo[i + 1].second);
                } else {
                    memo[i].first = min(1 + memo[i + 1].first, 2 + memo[i + 1].second);
                }
            }
        }
    }
    printf("%lld\n", memo[0].second);

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
