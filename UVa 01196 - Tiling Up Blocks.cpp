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

void tc(int n) {
    int l, w;
    vector<pair<int, int> > tiles;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &w);
        tiles.push_back({l, w});
    }
    sort(tiles.begin(), tiles.end());
    int k = 0, low, high, mid;
    vector<int> L(n + 5, -1);
    for (int i = 0; i < n; i++) {
        w = tiles[i].second;
        low = 0, high = k;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (L[mid] > w) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        L[low] = w;
        if (low == k) k++;
    }
    printf("%d\n", k);
}

void solve() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) tc(n);
    printf("*\n");
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
