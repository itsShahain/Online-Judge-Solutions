// https://icpcarchive.github.io/World%20Finals/ICPC%20World%20Finals/2011%20ICPC%20World%20Finals/problems.pdf#page=9
// Also available at UVa 01105 - Coffee Central
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


const int MAX_DIM = 2500;

void tc(int dx, int dy, int n, int q, int TC) {
    vector<vector<int> > PrefixSums(MAX_DIM + 5, vector<int>(MAX_DIM + 5, 0));
    int x, y;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        PrefixSums[-x + y + 1010][x + y + 10] = 1;
    }

    for (int row = 1; row <= MAX_DIM; row++) {
        for (int col = 1; col <= MAX_DIM; col++) {
            PrefixSums[row][col] += PrefixSums[row][col - 1];
            PrefixSums[row][col] += PrefixSums[row - 1][col];
            PrefixSums[row][col] -= PrefixSums[row - 1][col - 1];
        }
    }

    int m;
    printf("Case %d:\n", TC);
    while (q--) {
        scanf("%d", &m);
        int ans = 0, temp;
        int right, left, top, bottom, currX, currY, bestX = INT_MAX, bestY = INT_MAX;

        for (int row = 1; row < MAX_DIM; row++) {
            for (int col = 1; col < MAX_DIM; col++) {
                if ((col + row - 1020) % 2 == 0 && (col - row + 1000) % 2 == 0
                    && (currY = (col + row - 1020) / 2) >= 1 && currY <= dy
                    && (currX = (col - row + 1000) / 2) >= 1 && currX <= dx) {
                    right = min(MAX_DIM, col + m);
                    left = max(1, col - m);
                    top = min(MAX_DIM, row + m);
                    bottom = max(1, row - m);
                    temp = PrefixSums[top][right] - PrefixSums[top][left - 1] - PrefixSums[bottom - 1][right] +
                           PrefixSums[bottom - 1][left - 1];
                    int bhadega = PrefixSums[top][right];
                    if (temp > ans) {
                        ans = temp;
                        bestY = currY;
                        bestX = currX;
                    } else if (temp == ans) {
                        if (currY < bestY) {
                            bestY = currY;
                            bestX = currX;
                        } else if (currY == bestY && currX < bestX) {
                            bestX = currX;
                        }
                    }
                }
            }
        }
        printf("%d (%d,%d)\n", ans, bestX, bestY);
    }
}


void solve() {
    int dx, dy, n, q, TC = 1;
    while (scanf("%d %d %d %d", &dx, &dy, &n, &q) != EOF && (dx != 0 || dy != 0 || n != 0 || q != 0)) tc(dx, dy, n, q, TC++);
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
