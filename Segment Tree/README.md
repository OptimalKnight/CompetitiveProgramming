# Segment Tree

Segment trees are a type of data structure used in computer science to efficiently answer range queries on arrays or other data structures. They are particularly useful when the data needs to be updated frequently and the queries need to be answered quickly.

The segment tree divides the data into smaller segments, where each segment represents a range of values in the original array. Each node in the tree represents a segment and contains information about that segment, such as the minimum or maximum value, the sum of the values, or any other aggregation function.

The tree is built recursively by dividing the data into smaller segments until each segment contains only one value. The leaf nodes of the tree represent individual values in the original array, and the parent nodes represent the aggregated information for their child nodes.

With the segment tree, range queries on the original array can be answered in logarithmic time, which is much faster than the linear time required by a brute-force approach. The segment tree can also handle updates to the original array in logarithmic time, making it a powerful tool for certain types of data processing tasks.

## Usage

To use the Segment Tree data structure, you can instantiate an object of the class and provide the size of the tree as the parameter N to the constructor. The constructor builds the tree and performs some precalculations, which takes O(nlog2(n)) time. This segment tree is implemented using lazy propagation.

Once you've created the Segment Tree, you can easily perform range queries on the array by calling the respective query method. For example, to find the minimum value in a range [L, R], you can call the range minimum query method. Similarly, to perform range updates, you can call the respective update method. It's important to note that the Segment Tree is 1-indexed.

One of the advantages of the Segment Tree data structure is its flexibility. You can easily modify the code to perform different types of queries and updates. For example, you can modify the code to find the range maximum, range sum, or range xor, among other things. You can also change the type of update operation to perform subtraction, assignment, or other types of modifications.

## Time Complexity

- Constructor(N): O(N)
- update(low, high, value): O(log2(N))
- query(low, high): O(log2(N))

## Output

The output for the provided sample program would be,

    Minimum element in the range [3 - 9]: 2