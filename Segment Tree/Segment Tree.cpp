// Author: OptimalKnight
#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int inf = 1e18;

// Implementation of the segment tree (1-indexed) data structure
class SegmentTree {
private:
    int maxn;
    vector<int> seg, lazy;

    // Auxiliary function to help perform the update when required (addition)
    void pushDown(int node, int L, int R) {
        if (lazy[node] != 0) {
            seg[node] += lazy[node] * (R - L + 1);
            if (L != R) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    // Function to perform the given update (addition) in a given range in the tree
    void _update(int node, int L, int R, int low, int high, int value) {
        pushDown(node, L, R);
        if (L > R or L > high or R < low) {
            return;
        }
        if (L >= low and R <= high) {
            lazy[node] += value;
            pushDown(node, L, R);
            return;
        }

        int mid = L + (R - L) / 2;
        _update(2 * node, L, mid, low, high, value);
        _update(2 * node + 1, mid + 1, R, low, high, value);
        seg[node] = min(seg[2 * node], seg[2 * node + 1]);
    }

    // Function to query (minimum) and get the required element from a given range
    int _query(int node, int L, int R, int low, int high) {
        pushDown(node, L, R);
        if (L > R or L > high or R < low) {
            return inf;
        }
        if (L >= low and R <= high) {
            return seg[node];
        }

        int mid = L + (R - L) / 2;
        int que1 = _query(2 * node, L, mid, low, high);
        int que2 = _query(2 * node + 1, mid + 1, R, low, high);
        return min(que1, que2);
    }

public:
    // Class constructor
    SegmentTree(int N) {
        maxn = N;
        seg.assign(4 * maxn + 10, 0);
        lazy.assign(4 * maxn + 10, 0);
    }

    void update(int low, int high, int value) {
        _update(1, 1, maxn, low, high, value);
    }

    int query(int low, int high) {
        return _query(1, 1, maxn, low, high);
    }
};

signed main() {
    int N = 10;
    vector<int> V = {1, 7, 4, 3, 2, 6, 9, 6, 4, 2};
    SegmentTree obj(N);

    for (int i = 0; i < N; i++) {
        obj.update(i + 1, i + 1, V[i]);
    }

    cout << "Minimum element in the range [3 - 9]: " << obj.query(3, 9) << endl;
}