#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// char str[20];
// scanf("%[^ ]%*c", str);
// scanf("%[^\n]%*c", str);

struct CustomCompare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0]
        ? true
        : a[0] < b[0]
        ? false
        : a[1] >= b[1];
    }
};

int main() {
    // setIO("test");
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        CustomCompare
        > pq;

    int QNum, period;
    while(scanf("Register %d %d\n", &QNum, &period) == 2) {
        pq.push(vector<int>{period, QNum, period});
    }

    scanf("%*c");
    int k;
    scanf("%d", &k);
    while(k--) {
        vector<int> tp = pq.top(); pq.pop();
        printf("%d\n", tp[1]);
        pq.push(vector<int>{tp[0] + tp[2], tp[1], tp[2]});
    }
}
