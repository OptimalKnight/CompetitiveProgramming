# Lowest Common Ancestor

The lowest common ancestor (LCA) of two nodes in a tree is the deepest node that is a common ancestor of both nodes. Binary lifting is a technique that can be used to efficiently compute the LCA of two nodes in a tree. The algorithm involves precomputing information about the ancestors of each node in the tree and then using this information to answer LCA queries in O(log N) time, where N is the number of nodes in the tree. The precomputation step takes O(N log N) time, but once the information has been computed, LCA queries can be answered efficiently

## Output

    Lowest common ancestor of 2 and 4 (0-indexed): 0
    Distance between 2 and 4 (0-indexed) in the tree: 4