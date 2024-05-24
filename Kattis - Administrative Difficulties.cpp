#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std::chrono;
// #define FILE_IO
// #define RUNTIME

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

// char str[20];
// scanf("%[^ ]%*c", str);
// scanf("%[^\n]%*c", str);

void tc() {
    int n, m;
    scanf("%d %d", &n, &m);
    unordered_map<string, tuple<int, int, int> > car_details;

    string N;
    int p, q, l;
    for (int i = 0; i < n; i++) {
        cin >> N;
        scanf("%d %d %d", &p, &q, &l);
        car_details[N] = {p, q, l};
    }

    unordered_map<string, stack<char> > spy_events;
    unordered_map<string, string> spy_car;
    map<string, double> spy_costs;

    int t;
    string S;
    char e;
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        cin >> S;
        scanf("%*c");
        scanf("%c", &e);
        if (e == 'p') {
            cin >> spy_car[S];
            if (!spy_events[S].empty()) {
                spy_costs[S] = -1.0 * INFINITY;
            } else {
                spy_events[S].push(e);
                spy_costs[S] += ceil(get<1>(car_details[spy_car[S]]) * 1.0);
            }
        } else if (e == 'a') {
            double percentage;
            cin >> percentage;
            if (spy_events[S].empty() || spy_events[S].top() != 'p') {
                spy_costs[S] = -1.0 * INFINITY;
            } else {
                spy_costs[S] += ceil((percentage * get<0>(car_details[spy_car[S]])) / 100.0);
            }
        } else if (e == 'r') {
            double d;
            cin >> d;
            if (spy_events[S].empty() || spy_events[S].top() != 'p') {
                spy_costs[S] = -1.0 * INFINITY;
            } else {
                spy_events[S].pop();
                spy_costs[S] += ceil(get<2>(car_details[spy_car[S]]) * d);
            }
        }
    }

    for (auto it = spy_costs.begin(); it != spy_costs.end(); ++it) {
        if (it->second == -1.0 * INFINITY || !spy_events[it->first].empty()) {
            printf("%s INCONSISTENT\n", (it->first).c_str());
        } else {
            // cout << (it->first) << " " << ceil(it->second) << '\n';
            printf("%s %.0lf\n", (it->first).c_str(), ceil(it->second));
        }
    }
}

void solve() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        tc();
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
