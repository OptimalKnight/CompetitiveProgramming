# Segment Tree

Segment trees are a type of data structure used in computer science to efficiently answer range queries on arrays or other data structures. They are particularly useful when the data needs to be updated frequently and the queries need to be answered quickly.

The segment tree divides the data into smaller segments, where each segment represents a range of values in the original array. Each node in the tree represents a segment and contains information about that segment, such as the minimum or maximum value, the sum of the values, or any other aggregation function.

The tree is built recursively by dividing the data into smaller segments until each segment contains only one value. The leaf nodes of the tree represent individual values in the original array, and the parent nodes represent the aggregated information for their child nodes.

With the segment tree, range queries on the original array can be answered in logarithmic time, which is much faster than the linear time required by a brute-force approach. The segment tree can also handle updates to the original array in logarithmic time, making it a powerful tool for certain types of data processing tasks.

## Output

    Minimum element in the range [3 - 9]: 2