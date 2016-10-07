#ifndef BST_H
#define BST_H

/*
*   Just a plain Binary Search Tree
*/

// data node structure
template<typename V>
struct Node
{
    Node(V v)
    {
        value = v;
        left = nullptr;
        right = nullptr;
    }
    V value;
    Node* left;
    Node* right;
};

// helper function to completely destroy the pointer
// as its known that deleting would not remove
// the pointer to point to the assigned location
template<typename T> inline void destroy(T*& p) { delete p; p = nullptr; }

// binary search tree
template <typename V>
class BST
{
public:
    // creates empty BST
    BST();
    // creates BST with value as its root node
    BST(V value);

    void insert(V value);
    bool find(V value);
    void remove(V value);
    // print order: Root, Left subtree, Right subtree
    void inorderPrint();

protected:
    void insert(Node<V>* &tree, V value);
    bool find(Node<V>* &tree, V value);
    void remove(Node<V>* &tree, V value);

    void print(Node<V>* &tree);

private:
    Node<V>* root;
};

#endif // BST_H
