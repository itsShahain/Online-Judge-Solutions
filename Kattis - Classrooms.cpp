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
    int n, k;
    scanf("%d %d", &n, &k);
    vector<pair<int, int>> is(n);
    multiset<int> rooms;
    pair<int, int> t;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t.first, &t.second);
        is[i] = t;
    }

    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second
                ? true
                : a.second > b.second
                ? false
                : a.first > b.first;
    };

    sort(is.begin(), is.end(), cmp);
    int ans = 0; multiset<int>::iterator it;
    for (int i = 0; i < n; i++) {
        it = rooms.lower_bound(is[i].first);
        if (it == rooms.begin()) {
            if (rooms.size() < k) {
                rooms.insert(is[i].second); ans++;
            }
        } else {
            ans++; rooms.erase(--it); rooms.insert(is[i].second);
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
