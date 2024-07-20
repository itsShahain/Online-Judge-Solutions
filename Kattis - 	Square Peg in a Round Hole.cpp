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
    int N, M, K; scanf("%d %d %d", &N, &M, &K);
    double p[N], c[M], s[K];
    for (int i = 0; i < N; i++) scanf("%lf", &p[i]);
    for (int i = 0; i < M; i++) scanf("%lf", &c[i]);
    for (int i = 0; i < K; i++) scanf("%lf", &s[i]);

    sort(p, p + N);
    sort(c, c + M);
    sort(s, s + K);

    int i = 0, j = 0, k = 0, ans = 0;

        while (i < N) {
            if (j < M && c[j] < p[i]) {
                ans++; j++;
            } else if (k < K && s[k] < p[i] * sqrt(2.0)) {
                ans++; k++;
            }
            i++;
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
