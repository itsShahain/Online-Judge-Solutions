// First ever interaction problem :)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
int w1, w2;
ll low, high, delta, l1, r1, l2, r2, mid, ans;

void converge() {
    if (high - low + 1 == 4) {
        l1 = low;
        r1 = low + 1;
        l2 = low + 1;
        r2 = low + 2;
        printf("Q %lld %lld %lld %lld\n", l1, r1, l2, r2);
        cout.flush();
        scanf("%d %d", &w1, &w2);
        if (w1 == 1 && w2 == 0) {
            ans = l1;
        } else if (w1 == 1 && w2 == 1) {
            ans = r1;
        } else if (w1 == 0 && w2 == 1) {
            ans = r2;
        } else {
            ans = high;
        }
    } else if (high - low + 1 == 3) {
        l1 = low;
        r1 = low;
        l2 = low + 1;
        r2 = low + 1;
        printf("Q %lld %lld %lld %lld\n", l1, r1, l2, r2);
        cout.flush();
        scanf("%d %d", &w1, &w2);
        if (w1 == 1 && w2 == 0) {
            ans = l1;
        } else if (w1 == 0 && w2 == 1) {
            ans = l2;
        } else {
            ans = high;
        }
    } else if (high - low + 1 == 2) {
        l1 = low;
        r1 = low;
        l2 = high;
        r2 = high;
        printf("Q %lld %lld %lld %lld\n", l1, r1, l2, r2);
        cout.flush();
        scanf("%d %d", &w1, &w2);
        if (w1 == 1 && w2 == 0) {
            ans = low;
        } else if (w1 == 0 && w2 == 1) {
            ans = high;
        }
    }
}

void quat_search() {
    while (low < high) {
        if (high - low + 1LL <= 4LL) {
            converge();
            return;
        }
        delta = (high - low + 1LL) / 4;
        l1 = low;
        r1 = low + 2 * delta;
        l2 = low + delta;
        r2 = low + 3 * delta;
        printf("Q %lld %lld %lld %lld\n", l1, r1, l2, r2);
        cout.flush();
        scanf("%d %d", &w1, &w2);
        if (w1 == 1 && w2 == 0) {
            low = max(1LL, l1 - 1LL);
            high = l2;
        } else if (w1 == 1 && w2 == 1) {
            low = max(1LL, l2 - 1LL);
            high = min(N, r1 + 1LL);
        } else if (w1 == 0 && w2 == 1) {
            low = r1;
            high = min(N, r2 + 1LL);
        } else {
            low = r2;
            high = min(N, high + 1LL);
        }
    }
}

int main() {
    scanf("%lld", &N);
    low = 1LL, high = N, ans = 1LL;
    quat_search();
    printf("A %lld\n", ans);
}
