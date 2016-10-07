#include "bst.h"
#include <iostream>

template <typename V>
BST<V>::BST() : root{nullptr}
{

}
template <typename V>
BST<V>::BST(V value) : root{new Node<V>(value)}
{

}

template <typename V>
void BST<V>::insert(V value)
{
    insert(root, value);
}

template <typename V>
void BST<V>::insert(Node<V>* &tree, V value)
{
    if (tree == nullptr)
    {
        tree = new Node<V>(value);
    }
    else if (value < tree->value)
    {
        // put smaller elements on left branch
        insert(tree->left, value);
    }
    else if (value > tree->value)
    {
        // put larger elements on right branch
        insert(tree->right, value);
    }
}

template <typename V>
bool BST<V>::find(V value)
{
    return find(root, value);
}

template <typename V>
bool BST<V>::find(Node<V>* &tree, V value)
{
    // special case when tree is empty
    if (tree == nullptr)
    {   
        return false;
    }
    else if (value == tree->value)
    {
        return true;
    }
    else if (value < tree->value)
    {
        // check the smaller elements on left branch
        return find(tree->left, value);
    }
    else
    {
        // check the larger elements on right branch
        return find(tree->right, value);
    }
}

template <typename V>
void BST<V>::remove(V value)
{
    remove(root, value);
}

template <typename V>
void BST<V>::remove(Node<V>* &tree, V value)
{
    if (tree->value == value)
    {
        // delete the node
        if (tree->left == nullptr && tree->right == nullptr)
        {
            // leaf node, just remove the leaf
            // set the pointer to null
            // because deleting it will keep the address
            // and wont set it to null automatically
            destroy(tree);
        }
        else if (tree->left == nullptr && tree->right != nullptr)
        {
            // node has just one right subtree
            // swap the target node data with the data of first node on right
            Node<V>* node_to_delete = tree->right;
            std::swap(tree->value, tree->right->value);
            // make pointers point to node on right of target node
            tree->left = node_to_delete->left;
            tree->right = node_to_delete->right;
            // destroy the node right of target node
            destroy(node_to_delete);
        }
        else if (tree->right == nullptr && tree->left != nullptr)
        {
            // logic for the left subtree is the same as for right
            Node<V>* node_to_delete = tree->left;
            std::swap(tree->value, tree->left->value);
            tree->left = node_to_delete->left;
            tree->right = node_to_delete->right;
            destroy(node_to_delete);
        }
        else
        {
            // TODO:
            // node has both branches
            // find right-most node of left sub-tree
            Node<V>* node_to_delete = tree->left;
            while (node_to_delete->right != nullptr)
                node_to_delete = node_to_delete->right;
            // swap the values
            std::swap(tree->value, node_to_delete->value);
            // destroy the duplicated node
            destroy(node_to_delete);
        }
    }
    else if (value < tree->value)
    {
        // look in left subtree
        remove(tree->left, value);
    }
    else if (value > tree->value)
    {
        // look in right subtree
        remove(tree->right, value);
    }
}

template <typename V>
void BST<V>::inorderPrint()
{
    if (root != nullptr)
    {
        std::cout << root->value << " ";
        print(root->left);
        print(root->right);
    }
    // go to next line when inorder printing is finished
    std::cout << std::endl;
}

template <typename V>
void BST<V>::print(Node<V>* &tree)
{
    if (tree != nullptr)
    {
        std::cout << tree->value << " ";
        print(tree->left);
        print(tree->right);
    }
}

template <typename V>
Node<V>* rightmost(Node<V>*& tree)
{

}
