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
    int ltime = 0, time;
    double profit;
    vector<int> times;
    vector<double> arr, profits;
    for (int i = 0; i < n; i++) {
        scanf("%d %lf", &time, &profit);
        times.push_back(time);
        profits.push_back(profit);
        arr.push_back(profit - (time - ltime) * 0.08);
        ltime = time;
    }

    for (int i = 1; i < arr.size(); i++) {
        arr[i] += arr[i - 1];
    }

    double best = DBL_MIN, tp;
    int bestStart = INT_MAX, bestEnd = INT_MIN;
    for (int start = 0; start < times.size(); start++) {
        for (int end = start; end < times.size(); end++) {
            tp = profits[start] - 0.08 + arr[end] - arr[start];
            if (tp > best) {
                best = tp;
                bestStart = times[start];
                bestEnd = times[end];
            } else if (tp == best) {
                if (times[end] - times[start] < bestEnd - bestStart) {
                    bestStart = times[start];
                    bestEnd = times[end];
                } else if (times[end] - times[start] == bestEnd - bestStart && times[start] < bestStart) {
                    bestStart = times[start];
                    bestEnd = times[end];
                }
            }
        }
    }

    if (best - 0.0 > 1e-5) {
        printf("%.2lf %d %d\n", best, bestStart, bestEnd);
    } else {
        printf("no profit\n");
    }
}

void solve() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) tc(n);
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
