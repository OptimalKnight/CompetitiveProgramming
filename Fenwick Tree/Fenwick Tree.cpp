// Author: OptimalKnight
#include <bits/stdc++.h>
using namespace std;

#define int long long int

// Implementation of the fenwick tree (0-indexed) data structure
class FenwickTree {
private:
    int maxn;
    vector<int> tree;

public:
    // Class constructor to initialise the required variables
    FenwickTree(int N) {
        maxn = N;
        tree.assign(maxn + 1, 0);
    }

    // Function to update (add) a specifice value at the required index in the data structure
    void update(int index, int value) {
        ++index;
        while (index <= maxn) {
            tree[index] += value;
            index += (index & (-index));
        }
        return;
    }

    // Function to calculate the prefix sum of the vector till the specified index
    int query(int index) {
        ++index;
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index -= (index & (-index));
        }
        return result;
    }
};

signed main() {
    int N = 10;
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    FenwickTree obj(N);
    for (int i = 0; i < N; i++) {
        obj.update(i, vec[i]);
    }

    cout << "The sum of elements of the given vector from index '0' to index '7': " << obj.query(7) << endl;
    cout << "The sum of elements of the given vector from index '3' to index '7': " << (obj.query(7) - obj.query(2)) << endl;
}
