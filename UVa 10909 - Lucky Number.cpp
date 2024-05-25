// Need to learn Splay Trees

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std::chrono;
// #define FILE_IO
// #define RUNTIME

typedef tree<int, null_type, less<int>, splay_tree_tag, tree_order_statistics_node_update> ost;
typedef long long ll;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}


const int mx = 2000000;
int dp[mx];
int lucky[mx];

// char str[20];
// scanf("%[^ ]%*c", str);
// scanf("%[^\n]%*c", str);

void tc(int n) {
    if (n & 1) {
        // impossible since all lucky nums are odd, so adding two would be even
        printf("%d is not the sum of two luckies!\n", n);
    } else {
        if (!dp[n]) {
            dp[n] = -1;
            for (int i = n / 2; i >= 1; --i) {
                if (lucky[i] && lucky[n - i]) {
                    dp[n] = i;
                    break;
                }
            }
        }
        if (dp[n] == -1) {
            cout << n << " is not the sum of two luckies!\n";
        } else {
            cout << n << " is the sum of " << dp[n] << " and " << n - dp[n] << ".\n";
        }
    }
}

void solve() {
    ost tree;
    for (int i = 1; i <= mx; i = i + 2) {
        tree.insert(i);
    }

    for (ost::iterator it = ++tree.begin(); it != tree.end(); ++it) {
        int strike = *it;
        for (int j = strike; j <= mx; j += strike - 1) {
            if (j > tree.size()) break;
            tree.erase(tree.find_by_order(j - 1));
        }
    }

    int n;

    for (ost::iterator it = tree.begin(); it != tree.end(); ++it) {
        lucky[*it] = 1;
    }

    while (scanf("%d", &n) != EOF) {
        tc(n);
    }
}


int main() {
    auto start = high_resolution_clock::now();
#ifdef FILE_IO
    setIO("test");
#endif
    solve();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
#ifdef RUNTIME
    cout << "\n"
            << "Run time : " << duration.count() << " microseconds";
#endif
}

using namespace __gnu_pbds;
using namespace std::chrono;
// #define FILE_IO
// #define RUNTIME

typedef tree<int, null_type, less<int>, splay_tree_tag, tree_order_statistics_node_update> ost;
typedef long long ll;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}


const int mx = 2000000;
int dp[mx];
int lucky[mx];

// char str[20];
// scanf("%[^ ]%*c", str);
// scanf("%[^\n]%*c", str);

void tc(int n) {
    if (n & 1) {
        // impossible since all lucky nums are odd, so adding two would be even
        printf("%d is not the sum of two luckies!\n", n);
    } else {
        if (!dp[n]) {
            dp[n] = -1;
            for (int i = n / 2; i >= 1; --i) {
                if (lucky[i] && lucky[n - i]) {
                    dp[n] = i;
                    break;
                }
            }
        }
        if (dp[n] == -1) {
            cout << n << " is not the sum of two luckies!\n";
        } else {
            cout << n << " is the sum of " << dp[n] << " and " << n - dp[n] << ".\n";
        }
    }
}

void solve() {
    ost tree;
    for (int i = 1; i <= mx; i = i + 2) {
        tree.insert(i);
    }

    for (ost::iterator it = ++tree.begin(); it != tree.end(); ++it) {
        int strike = *it;
        for (int j = strike; j <= mx; j += strike - 1) {
            if (j > tree.size()) break;
            tree.erase(tree.find_by_order(j - 1));
        }
    }

    int n;

    for (ost::iterator it = tree.begin(); it != tree.end(); ++it) {
        lucky[*it] = 1;
    }

    while (scanf("%d", &n) != EOF) {
        tc(n);
    }
}


int main() {
    auto start = high_resolution_clock::now();
#ifdef FILE_IO
    setIO("test");
#endif
    solve();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
#ifdef RUNTIME
    cout << "\n"
            << "Run time : " << duration.count() << " microseconds";
#endif
}
