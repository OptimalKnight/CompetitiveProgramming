# Disjoing Set Union

Disjoint set union, also known as union-find data structure, is a data structure that allows efficiently managing a collection of disjoint sets. Each set is represented by a unique root element, and elements within the same set share the same root element. The data structure supports two main operations: union, which merges two sets into a single set, and find, which determines the root element (i.e., the representative) of the set to which an element belongs. Disjoint set union has many applications, including in graph algorithms, image processing, and computer science education.

## Usage

The DSU (Disjoint Set Union) data structure is a useful tool for solving problems related to connected components in graphs. To use the DSU data structure, you can instantiate an object of the class and provide the maximum number of elements in a set as the parameter N. This implementation also includes the path compression and union by rank heuristics as well.

When you create an instance of the DSU class, a set containing only the element itself is created in the constructor. You can then use the union method to unite two different sets. This is done by finding the representative element of each set and making one of them the parent of the other. By doing this, all elements in both sets become part of the same connected component.

In addition to uniting sets, you can also find the representative element of a set using the find method. This method returns the root of the tree that the element belongs to, which is also the representative element of the set. You can also find the size of a set using the size method.

## Time Complexity

- Constructor(N): O(n)
- find(num): amortized O(1)
- size(num): O(1)
- Union(x, y): amortized O(1)

## Output

The output for the provided sample program would be,

    Parent of 1: 1
    Parent of 5: 3
    Parent of 1: 3
    Parent of 5: 3