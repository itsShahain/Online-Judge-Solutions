#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std::chrono;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

// char str[20];
// scanf("%[^ ]%*c", str);
// scanf("%[^\n]%*c", str);

void tc() {
    int B, GNumber, BNumber;
    scanf("%d %d %d", &B, &GNumber, &BNumber);
    priority_queue<
        int,
        vector<int>,
        less<int>
    > GArmy, BArmy;
    int soldier;
    for (int i = 0; i < GNumber; i++) {
        scanf("%d", &soldier);
        GArmy.push(soldier);
    }

    for (int i = 0; i < BNumber; i++) {
        scanf("%d", &soldier);
        BArmy.push(soldier);
    }

    while (true) {
        // simulate
        if (GArmy.empty() && BArmy.empty()) {
            printf("green and blue died\n");
            return;
        } else if (GArmy.empty()) {
            printf("blue wins\n");
            while (!BArmy.empty()) {
                printf("%d\n", BArmy.top());
                BArmy.pop();
            }
            return;
        } else if (BArmy.empty()) {
            printf("green wins\n");
            while (!GArmy.empty()) {
                printf("%d\n", GArmy.top());
                GArmy.pop();
            }
            return;
        } else {
            int green, blue;
            vector<int> greenGuys, blueGuys;
            for (int i = 0; i < B && !GArmy.empty() && !BArmy.empty(); i++) {
                green = GArmy.top();
                GArmy.pop();
                blue = BArmy.top();
                BArmy.pop();
                if (green == blue) {
                    continue;
                } else if (green > blue) {
                    green -= blue;
                    greenGuys.push_back(green);
                } else {
                    blue -= green;
                    blueGuys.push_back(blue);
                }
            }

            for (int j = 0; j < greenGuys.size(); j++) {
                GArmy.push(greenGuys[j]);
            }

            for (int j = 0; j < blueGuys.size(); j++) {
                BArmy.push(blueGuys[j]);
            }
        }
    }
}

void solve() {
    int TC;
    scanf("%d", &TC);
    for(int i = 0; i < TC; i++) {
        tc();
        if(i != TC - 1) printf("\n");
    }
}

// #define FILE_IO
// #define RUNTIME

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
