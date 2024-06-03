// https://icpc.global/worldfinals/problems/2007-ICPC-World-Finals/2007WorldFinalProblemSet.pdf#page=13
// Also available at UVa 1064 - Network
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define FILE_IO

int iVal, mVal;

typedef long long ll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + "_in.txt").c_str(), "r", stdin);
    freopen((s + "_out.txt").c_str(), "w", stdout);
}

#define LSOne(S) ((S) & -(S))                    // the key operation

typedef long long ll; // for extra flexibility
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {
    // index 0 is not used
private:
    vll ft; // internal FT is an array
public:
    FenwickTree(int m) { ft.assign(m + 1, 0); } // create an empty FT

    void build(const vll &f) {
        int m = (int) f.size() - 1; // note f[0] is always 0
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            // O(m)
            ft[i] += f[i]; // add this value
            if (i + LSOne(i) <= m) // i has parent
                ft[i + LSOne(i)] += ft[i]; // add to that parent
        }
    }

    FenwickTree(const vll &f) { build(f); } // create FT based on f

    FenwickTree(int m, const vi &s) {
        // create FT based on s
        vll f(m + 1, 0);
        for (int i = 0; i < (int) s.size(); ++i) // do the conversion first
            ++f[s[i]]; // in O(n)
        build(f); // in O(m)
    }

    ll rsq(int j) {
        // returns RSQ(1, j)
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // inc/exclusion

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, ll v) {
        for (; i < (int) ft.size(); i += LSOne(i))
            ft[i] += v;
    }

    int select(ll k) {
        // O(log m)
        int p = 1;
        while (p * 2 < (int) ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i + p]) {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

class RUPQ {
    // RUPQ variant
private:
    FenwickTree ft; // internally use PURQ FT
public:
    RUPQ(int m) : ft(FenwickTree(m)) {
    }

    void range_update(int ui, int uj, ll v) {
        ft.update(ui, v); // [ui, ui+1, .., m] +v
        ft.update(uj + 1, -v); // [uj+1, uj+2, .., m] -v
    } // [ui, ui+1, .., uj] +v
    ll point_query(int i) { return ft.rsq(i); } // rsq(i) is sufficient
};

class RURQ {
    // RURQ variant
private: // needs two helper FTs
    RUPQ rupq; // one RUPQ and
    FenwickTree purq; // one PURQ
public:
    RURQ() : rupq(0), purq(0) {
    } // Default constructor
    RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {
    } // initialization
    void range_update(int ui, int uj, ll v) {
        rupq.range_update(ui, uj, v); // [ui, ui+1, .., uj] +v
        purq.update(ui, v * (ui - 1)); // -(ui-1)*v before ui
        purq.update(uj + 1, -v * uj); // +(uj-ui+1)*v after uj
    }

    ll rsq(int j) {
        return rupq.point_query(j) * j - // optimistic calculation
               purq.rsq(j); // cancelation factor
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // standard
};

int message[10], currMessage;
int messageSize[10];
int packetMessageNum[1010];
int packetMessageStartByte[1010];
int packetMessageEndByte[1010];
bitset<6> alreadySent;
bool prevAllSent;

void tc(int N, int M) {
    int currBufferSize, maxBufferSize, minBufferOverall = INT_MAX;
    memset(message, 0, sizeof message);
    memset(messageSize, 0, sizeof messageSize);
    memset(packetMessageNum, 0, sizeof packetMessageNum);
    memset(packetMessageStartByte, 0, sizeof packetMessageStartByte);
    memset(packetMessageEndByte, 0, sizeof packetMessageEndByte);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &messageSize[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &packetMessageNum[i]);
        scanf("%d", &packetMessageStartByte[i]);
        scanf("%d", &packetMessageEndByte[i]);
    }

    for (int i = 1; i <= N; i++) {
        message[i] = i;
    }

    do {
        alreadySent.reset();
        currBufferSize = 0;
        maxBufferSize = 0;
        vector<RURQ> fts(N + 1);
        for (int i = 1; i <= N; i++) {
            fts[i] = RURQ(messageSize[i]);
        }

        for (int i = 0; i < M; i++) {
            iVal = i;
            currMessage = packetMessageNum[i];
            prevAllSent = true;
            for (int j = 1; message[j] != currMessage && prevAllSent; j++) {
                prevAllSent &= alreadySent[message[j]];
            }

            fts[currMessage].range_update(packetMessageStartByte[i], packetMessageEndByte[i], 1);

            if (prevAllSent) {
                if (fts[currMessage].rsq(1, packetMessageStartByte[i] - 1) == packetMessageStartByte[i] - 1) {
                    // can send directly
                    int low = packetMessageEndByte[i] + 1, high = messageSize[currMessage];
                    if (low <= high) {
                        while (low < high) {
                            int mid = low + (high - low + 1) / 2;
                            if (fts[currMessage].rsq(low, mid) == mid - low + 1) {
                                low = mid;
                            } else high = mid - 1;
                        }
                        if (fts[currMessage].rsq(low, low)) {
                            currBufferSize -= low - packetMessageEndByte[i];
                            maxBufferSize = max(maxBufferSize, currBufferSize);
                        }
                    }
                } else {
                    currBufferSize += packetMessageEndByte[i] - packetMessageStartByte[i] + 1;
                    maxBufferSize = max(maxBufferSize, currBufferSize);
                }
            } else {
                currBufferSize += packetMessageEndByte[i] - packetMessageStartByte[i] + 1;
                maxBufferSize = max(maxBufferSize, currBufferSize);
            }

            if (fts[currMessage].rsq(messageSize[currMessage]) == messageSize[currMessage])
                alreadySent[currMessage] = true;
        }
        minBufferOverall = min(minBufferOverall, maxBufferSize);
    } while (next_permutation(message + 1, message + N + 1));
    printf("%d\n\n", minBufferOverall);
}

void solve() {
    int N, M;
    int TC = 1;
    while (scanf("%d %d", &N, &M), N != 0 || M != 0) {
        printf("Case %d: ", TC);
        tc(N, M);
        TC++;
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
