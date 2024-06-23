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
    int M;
    scanf("%d", &M);
    vector<int> ds(M);
    for (int i = 0; i < M; i++) scanf("%d", &ds[i]);

    vector<vector<int> > memo(M + 1, vector<int>(1000 + 1, -1));
    vector<vector<char> > transition(M + 1, vector<char>(1000 + 1, '$'));

    memo[M][0] = 0;
    for (int height = 1; height <= 1000; height++) memo[M][height] = INT_MAX;

    for (int i = M - 1; i >= 0; i--) {
        for (int height = 0; height <= 1000; height++) {
            int &ans = memo[i][height];
            if (ds[i] <= height) {
                if (memo[i + 1][height - ds[i]] == INT_MAX && memo[i + 1][height + ds[i]] == INT_MAX) {
                    ans = INT_MAX;
                } else if (memo[i + 1][height - ds[i]] <= memo[i + 1][height + ds[i]]) {
                    transition[i][height] = 'D';
                    ans = max(height, memo[i + 1][height - ds[i]]);
                } else {
                    transition[i][height] = 'U';
                    ans = max(height, memo[i + 1][height + ds[i]]);
                }
                // ans = max(height, min(memo[i + 1][height - ds[i]], memo[i + 1][height + ds[i]]));
            } else {
                if (memo[i + 1][height + ds[i]] == INT_MAX) {
                    ans = INT_MAX;
                } else {
                    transition[i][height] = 'U';
                    ans = max(ans, memo[i + 1][height + ds[i]]);
                }
            }
        }
    }

    if (transition[0][0] == '$') {
        printf("IMPOSSIBLE\n");
    } else {
        int i = 0, height = 0;
        while (transition[i][height] != '$') {
            printf("%c", transition[i][height]);
            if (transition[i][height] == 'U') height += ds[i];
            else height -= ds[i];
            i++;
        }
        printf("\n");
    }
}

void solve() {
    int N;
    scanf("%d", &N);
    while (N--) tc();
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
