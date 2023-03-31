# Lowest Common Ancestor

The lowest common ancestor (LCA) of two nodes in a tree is the deepest node that is a common ancestor of both nodes. Binary lifting is a technique that can be used to efficiently compute the LCA of two nodes in a tree. The algorithm involves precomputing information about the ancestors of each node in the tree and then using this information to answer LCA queries in O(log N) time, where N is the number of nodes in the tree. The precomputation step takes O(N log N) time, but once the information has been computed, LCA queries can be answered efficiently

## Usage

To use the LCA data structure, you can create an instance of the class and provide the tree, number of elements in the tree, and the maximum number of bits required to represent a node as a binary number as tree, N, and D, respectively, to the constructor. The constructor performs some precalculations to build the data structure, which takes O(nlog2(n)) time. Note that the data structure is 0-indexed.

Once you've created the LCA data structure, you can easily find the LCA of two nodes in the tree by calling the respective method. This method takes two node indices as arguments and returns the index of the LCA. You can also find the distance between any two nodes in the tree by using a combination of the LCA and some basic arithmetic.

The LCA data structure is highly efficient and can be used to solve a wide range of problems related to trees. For example, you can use it to find the distance between two nodes in a tree, or to find the size of the subtree rooted at a particular node. You can also use it to solve more complex problems, such as finding the diameter of a tree or computing the centroid decomposition of a tree

## Time Complexity

- Constructor(tree, N, D): O(Nlog2(N))
- getLCA(u, v): O(log2(N))
- getDist(u, v): O(1)

## Output

The output for the provided sample program would be,

    Lowest common ancestor of 2 and 4 (0-indexed): 0
    Distance between 2 and 4 (0-indexed) in the tree: 4