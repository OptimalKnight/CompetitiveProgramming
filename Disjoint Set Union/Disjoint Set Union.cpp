// Author: OptimalKnight
#include <bits/stdc++.h>
using namespace std;

#define int long long int

// Implementation of the disjoing set union data structure
class DisjoingSetUnion {
private:
    int maxn;
    vector<int> parent;

public:
    // Class constructor
    DisjoingSetUnion(int N) {
        maxn = N;
        parent.assign(N + 1, -1);
    }

    // Function to find the parent element of the set to which the given element belongs
    int find(int num) {
        return ((parent[num] < 0) ? num : parent[num] = find(parent[num]));
    }

    // Function to find the size of the set to which the given element belongs
    int size(int num) {
        return -parent[find(num)];
    }

    // Function to merge two sets containing the given two elements
    bool Union(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        if (parent[x] > parent[y]) {
            swap(x, y);
        }

        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
};

signed main() {
    int N = 5;
    vector<int> V = {1, 2, 3, 4, 5};
    DisjoingSetUnion obj(N);

    obj.Union(1, 2);
    obj.Union(3, 4);
    obj.Union(4, 5);

    cout << "Parent of 1: " << obj.find(1) << endl;
    cout << "Parent of 5: " << obj.find(5) << endl;

    obj.Union(2, 3);

    cout << "Parent of 1: " << obj.find(1) << endl;
    cout << "Parent of 5: " << obj.find(5) << endl;
}