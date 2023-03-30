// Author: OptimalKnight
#include <bits/stdc++.h>
using namespace std;

#define int long long int

// Implementation of the trie data structure
class Trie {
#define ALPHABET_SIZE 26
private:
    // Structure to represent a node of the trie
    struct node {
        struct node *child[ALPHABET_SIZE];
        bool isLeaf;
    };

    // Function to return a new node of the trie
    struct node *makeNode(void) {
        struct node *curr = new node;
        curr->isLeaf = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            curr->child[i] = NULL;
        }
        return curr;
    }

    // Root of the whole trie 
    struct node *root = makeNode();

    // Auxiliary function to check if a given node has no child
    bool isEmpty(node *curNode) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (curNode->child[i]) {
                return false;
            }
        }
        return true;
    }

    // Function to remove a given key from the trie
    node *_remove(node *curNode, string &key, int depth) {
        if (!curNode) {
            return NULL;
        }

        int SI = key.size();
        if (depth == SI) {
            curNode->isLeaf = false;
            if (isEmpty(curNode)) {
                delete (curNode);
                curNode = NULL;
            }
            return curNode;
        }

        int ind = key[depth] - 'a';
        curNode->child[ind] = _remove(curNode->child[ind], key, depth + 1);
        if (isEmpty(curNode) and !curNode->isLeaf) {
            delete (curNode);
            curNode = NULL;
        }
        return curNode;
    }

    // Function to display the current state of the trie
    void _display(node *curNode, string &str, int depth) {
        if (curNode->isLeaf) {
            cout << str << endl;
        }

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (curNode->child[i]) {
                str.push_back(i + 'a');
                _display(curNode->child[i], str, depth + 1);
                str.pop_back();
            }
        }
    }

public:
    // Function to insert a new key into the trie
    void insert(string &key) {
        struct node *curr = root;
        for (int i = 0; i < (int)key.size(); i++) {
            int ind = key[i] - 'a';
            if (!curr->child[ind]) {
                curr->child[ind] = makeNode();
            }
            curr = curr->child[ind];
        }
        curr->isLeaf = true;
    }

    // Function to search a particular key in the trie
    bool search(string &key) {
        struct node *curr = root;
        for (int i = 0; i < (int)key.size(); i++) {
            int ind = key[i] - 'a';
            if (!curr->child[ind]) {
                return false;
            }
            curr = curr->child[ind];
        }
        return curr->isLeaf;
    }

    // Remove wrapper function
    void remove(string &key) {
        _remove(root, key, 0);
    }

    // Display wrapper function
    void display(void) {
        string str = "";
        _display(root, str, 0);
    }
};

signed main() {
    int N = 5;
    vector<string> V = {"abcd", "efgh", "ijkl", "mnop", "qrst"};
    Trie obj;

    for (int i = 0; i < N; i++) {
        obj.insert(V[i]);
    }

    string s = "abcde";
    cout << "'" << s << "' is present in the list: " << obj.search(s) << endl;

    s = "abcd";
    cout << "'" << s << "' is present in the list: " << obj.search(s) << endl;

    obj.remove(s);
    cout << "'" << s << "' is present in the list: " << obj.search(s) << endl;
}