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

void tc() {
}

int cube(int x) {
    return x * x * x;
}

void solve() {
    for(int a = 2; a <= 200; a++) {
        for(int b = 2; b <= cbrt(cube(200)/3.0); b++) {
            for(int c = b; c <= 200; c++) {
                for(int d = c; d <= 200; d++) {
                    if(cube(a) == cube(b) + cube(c) + cube(d)) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
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
