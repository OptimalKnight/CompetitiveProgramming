# Fenwick Tree

A Fenwick tree, also known as a binary indexed tree, is a data structure that efficiently supports prefix-sum queries on an array. It allows computing the sum of the elements in a range of the array (i.e., a prefix) in O(log n) time, where n is the size of the array. The Fenwick tree achieves this by representing the array as a binary tree, where each node stores the sum of a range of elements. The tree is constructed in O(n log n) time, where n is the size of the array. The Fenwick tree can be used in many applications, including computing the inversion number of an array, computing the rank of an element in a sorted array, and solving dynamic programming problems that require computing prefix sums over different sub-ranges of an array.

## Output

    The sum of elements of the given vector from index '0' to index '7': 36
    The sum of elements of the given vector from index '3' to index '7': 30