# Fenwick Tree

A Fenwick tree, also known as a binary indexed tree, is a data structure that efficiently supports prefix-sum queries on an array. It allows computing the sum of the elements in a range of the array (i.e., a prefix) in O(log n) time, where n is the size of the array. The Fenwick tree achieves this by representing the array as a binary tree, where each node stores the sum of a range of elements. The tree is constructed in O(n log n) time, where n is the size of the array. The Fenwick tree can be used in many applications, including computing the inversion number of an array, computing the rank of an element in a sorted array, and solving dynamic programming problems that require computing prefix sums over different sub-ranges of an array.

## Usage

To use the Fenwick data structure, you can create an instance of the class and provide the maximum number of elements in the tree as the parameter N. It's important to note that the tree is 0-indexed.

Once you've created the Fenwick tree, you can easily query it to calculate the prefix sum of a particular index. You can also perform addition updates on the tree using the update method.

If you need to calculate range xor, prefix minimum, prefix maximum, along with other types of updates such as subtraction or assignment, you can modify the code at the appropriate places. These modifications are simple and require some understanding of how the data structure works.

Overall, the Fenwick data structure is a versatile and efficient way to perform prefix sum calculations and can be adapted to a wide range of use cases with just a few modifications to the code.

## Time Complexity

- Constructor(N): O(N)
- update(index, value): O(log2(N))
- query(index): O(log2(N))

## Output

The output for the provided sample program would be,

    The sum of elements of the given vector from index '0' to index '7': 36
    The sum of elements of the given vector from index '3' to index '7': 30