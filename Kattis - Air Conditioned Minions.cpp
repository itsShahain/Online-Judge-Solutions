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
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> is(N);
    pair<int, int> tp;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &tp.first, &tp.second);
        is[i] = tp;
    }

    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first
                ? true
                : a.first > b.first
                ? false
                : a.second > b.second;
    };

    sort(is.begin(), is.end(), cmp);

    int last = INT_MAX; int ans = 1;

    for (int i = 0; i < N; i++) {
        if (is[i].first > last) {
            ans++; last = is[i].second;
        } else {
            last = min(last, is[i].second);
        }
    }

    printf("%d\n", ans);
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
