# Trie

A trie, also known as a prefix tree, is a tree-like data structure used for efficient retrieval and storage of strings or sequences of characters. Each node in the trie represents a prefix or a complete string, and the edges represent the characters in the string. Tries can be used for a variety of tasks such as spell checking, auto-completion, and IP routing, and they have a time complexity of O(m) for insertion, search, and deletion operations, where m is the length of the string.

## Usage
 
The trie data structure is a tree-like structure that is commonly used to efficiently store and search for keys in a large dataset. To utilize this structure, you can instantiate an object of the class and utilize its methods for inserting, searching, or deleting keys in the data structure.

To modify the trie's alphabet size, you can adjust the value of the ALPHABET_SIZE variable. This variable determines the size of the alphabet used in the trie and can be set to 2 for binary strings or to a larger value for other types of strings.

While it is possible to display the contents of the trie data structure, this method is usually not necessary and is primarily present for debugging purposes. The trie data structure is typically used for its efficient insertion, searching, and deletion capabilities rather than its display functionality.

## Time Complexity

- insert(key): O(length(key))
- search(key): O(length(key))
- remove(key): O(length(key))
- display(): O(nm) [n: number of keys, m: maximum key length]

## Output

The output for the provided sample program would be,

    'abcde' is present in the list: 0
    'abcd' is present in the list: 1
    'abcd' is present in the list: 0