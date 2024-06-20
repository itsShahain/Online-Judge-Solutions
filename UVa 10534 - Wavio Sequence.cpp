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


vector<int> vi, LIS, LDS;

void tc(int N) {
    vi.resize(N);
    LIS.resize(N);
    LDS.resize(N);

    for (int i = 0; i < N; i++) scanf("%d", &vi[i]);

    int k = 0;
    vector<int> L(N + 5, INT_MIN);
    for (int i = 0; i < N; i++) {
        int low = 0, high = k, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (L[mid] >= vi[i]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        L[low] = vi[i];
        if (low == k) k++;
        LIS[i] = k;
    }

    k = 0;
    L.resize(N + 5, INT_MIN);
    for (int i = N - 1; i >= 0; i--) {
        int low = 0, high = k, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (L[mid] >= vi[i]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        L[low] = vi[i];
        if (low == k) k++;
        LDS[i] = k;
    }


    // for (int i = 0; i < N; i++) {
    //     int best = 0;
    //     for (int j = 0; j < i; j++) {
    //         if (vi[j] < vi[i] && LIS[j] > best) best = LIS[j];
    //     }
    //     LIS[i] = best + 1;
    // }
    //
    // for (int i = N - 1; i >= 0; i--) {
    //     int best = 0;
    //     for (int j = N - 1; j > i; j--) {
    //         if (vi[i] > vi[j] && LDS[j] > best) best = LDS[j];
    //     }
    //     LDS[i] = best + 1;
    // }

    int ans = 0;
    for (int i = 0; i < vi.size(); i++) {
        ans = max(ans, 2 * min(LIS[i] - 1, LDS[i] - 1) + 1);
    }
    printf("%d\n", ans);
}

void solve() {
    int N;
    while (scanf("%d", &N) != EOF) tc(N);
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
