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

    void _update(int node, int L, int R, int lo, int hi, int val) {
        pushDown(node, L, R);
        if (L > R or L > hi or R < lo) {
            return;
        }
        if (L >= lo and R <= hi) {
            lazy[node] += val;
            pushDown(node, L, R);
            return;
        }

        int mid = L + (R - L) / 2;
        _update(2 * node, L, mid, lo, hi, val);
        _update(2 * node + 1, mid + 1, R, lo, hi, val);
        seg[node] = min(seg[2 * node], seg[2 * node + 1]);
    }

    int _query(int node, int L, int R, int lo, int hi) {
        pushDown(node, L, R);
        if (L > R or L > hi or R < lo) {
            return inf;
        }
        if (L >= lo and R <= hi) {
            return seg[node];
        }

        int mid = L + (R - L) / 2;
        int que1 = _query(2 * node, L, mid, lo, hi);
        int que2 = _query(2 * node + 1, mid + 1, R, lo, hi);
        return min(que1, que2);
    }

public:
    SegmentTree(int N) {
        maxn = N;
        seg.assign(4 * maxn + 10, 0);
        lazy.assign(4 * maxn + 10, 0);
    }

    void update(int lo, int hi, int val) {
        _update(1, 1, maxn, lo, hi, val);
    }

    int query(int lo, int hi) {
        return _query(1, 1, maxn, lo, hi);
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