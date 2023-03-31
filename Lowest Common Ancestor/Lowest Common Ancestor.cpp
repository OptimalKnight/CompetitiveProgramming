// Author: OptimalKnight
#include <bits/stdc++.h>
using namespace std;

#define int long long int

// Class to implement the lowest common ancestor procedures for a given tree (0-indexed) using binary lifting
class LowestCommonAncestor {
private:
    int depth, maxn;
    vector<vector<int>> parent;

public:
    vector<int> dist;

    // Class constructor
    LowestCommonAncestor(vector<vector<int>> &tree, int N, int D) {
        maxn = N, depth = D;
        dist.assign(maxn, -1);
        parent = vector<vector<int>>(maxn, vector<int>(depth));

        dist[0] = 0;
        parent[0][0] = 0;
        vector<int> que(1, 0);
        for (int b = 0; b < (int)que.size(); b++) {
            for (auto x : tree[que[b]]) {
                if (dist[x] == -1) {
                    que.push_back(x);
                    parent[x][0] = que[b];
                    dist[x] = dist[que[b]] + 1;
                }
            }
        }

        for (int j = 1; j < depth; j++) {
            for (int i = 0; i < maxn; i++) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }

    // Function to get the LCA of the given two nodes
    int getLCA(int u, int v) {
        if (dist[u] < dist[v]) {
            swap(u, v);
        }

        for (int j = (depth - 1); j >= 0; j--) {
            if ((dist[u] - (1LL << j)) >= dist[v]) {
                u = parent[u][j];
            }
        }
        if (u == v) {
            return u;
        }

        for (int j = (depth - 1); j >= 0; j--) {
            if (parent[u][j] != parent[v][j]) {
                u = parent[u][j];
                v = parent[v][j];
            }
        }
        return parent[u][0];
    }

    // Function to get distance between the two given nodes
    int getDistance(int u, int v) {
        return dist[u] + dist[v] - (2 * dist[getLCA(u, v)]);
    }
};

signed main() {
    int N = 5, D = 3;
    vector<vector<int>> V = {{1, 3}, {0, 2}, {1}, {0, 4}, {3}};
    LowestCommonAncestor obj(V, N, D);

    cout << "Lowest common ancestor of 2 and 4 (0-indexed): " << obj.getLCA(2, 4) << endl;
    cout << "Distance between 2 and 4 (0-indexed) in the tree: " << obj.getDistance(2, 4) << endl;
}