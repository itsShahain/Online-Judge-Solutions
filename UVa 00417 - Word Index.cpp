#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct customComparator {
    bool operator()(const string& a, const string& b) const {
        return a.length() < b.length()
        ? true
        : a.length() > b.length()
        ? false
        : a < b;
    }
};

typedef tree<string, null_type, customComparator, rb_tree_tag, tree_order_statistics_node_update> ost;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// char str[20];
// scanf("%[^ ]%*c", str);
// scanf("%[^\n]%*c", str);

void solve() {
}

bool isValid(string s) {
    if (s.length() == 1) {
        return true;
    } else {
        for (int i = 1; i < s.length(); i++) {
            if (s[i] - s[i - 1] <= 0) return false;
        }
        return true;
    }
}

int main() {
    // setIO("test");
    ost tree;
    string s;

    for (int i = 'a'; i <= 'z'; i++) {
        string s1(1, i);
        tree.insert(s1);
    }

    for(char i = 'a'; i <= 'y'; i++) {
        for(char j = i + 1; j <= 'z'; j++) {
            tree.insert(string(1,i) + j);
        }
    }

    for (char i = 'a'; i <= 'x'; i++) {
        for (char j = i + 1; j <= 'y'; j++) {
            for (char k = j + 1; k <= 'z'; k++) {
                tree.insert(string(1, i) + j + k);
            }
        }
    }

    for (char i = 'a'; i <= 'w'; i++) {
        for(char j = i + 1; j <= 'x'; j++) {
            for(char k = j + 1; k <= 'y'; k++) {
                for(char l = k + 1; l <= 'z'; l++) {
                    tree.insert(string(1, i) + j + k + l);
                }
            }
        }
    }

    for(char i = 'a'; i <= 'v'; i++) {
        for(char j = i + 1; j <= 'w'; j++) {
            for(char k = j + 1; k <= 'x'; k++) {
                for(char l = k + 1; l <= 'y'; l++) {
                    for(char m = l + 1; m <= 'z'; m++) {
                        tree.insert(string(1, i) + j + k + l + m);
                    }
                }
            }
        }
    }

    while (cin >> s) {
        if (isValid(s)) {
            printf("%d\n", tree.order_of_key(s) + 1);
        } else {
            printf("%d\n", 0);
        }
    }
}
