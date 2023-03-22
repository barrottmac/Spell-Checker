//
// Created by barro on 2023-03-14.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include "binary_search_tree.h"

//Insert string into BST
void BinarySearchTree::insert(const std::string &str) {
    insert(str, m_root);
}

//Public function to balance a BST
void BinarySearchTree::balance_tree() {
    m_root = build_tree(m_root);
//    std::cout<< *this<<std::endl;
}

//Private function to balance tree
NodePtr BinarySearchTree::build_tree(NodePtr root) {
    // Store nodes of given BST in sorted order
    std::vector<Node *> nodes;
    store_bst_nodes(root, nodes);

    // Constructs BST from nodes[]
    int n = nodes.size();
    return build_tree_util(nodes, 0, n - 1);
}

NodePtr BinarySearchTree::build_tree_util(std::vector<NodePtr> &nodes, int start,
                                          int end) {
    // base case
    if (start > end)
        return nullptr;

    /* Get the middle element and make it root */
    int mid = (start + end) / 2;
    NodePtr node_ptr = nodes[mid];

    /* Using index in Inorder traversal, construct
       left and right subtress */
    node_ptr->m_left = build_tree_util(nodes, start, mid - 1);
    node_ptr->m_right = build_tree_util(nodes, mid + 1, end);

    return node_ptr;
}

//Private function to store nodes in a vector
void BinarySearchTree::store_bst_nodes(NodePtr root, std::vector<NodePtr> &nodes) {
    // Base case
    if (root == nullptr)
        return;

    // Store nodes in Inorder (which is sorted
    // order for BST)
    store_bst_nodes(root->m_left, nodes);
    nodes.push_back(root);
    store_bst_nodes(root->m_right, nodes);
}

//Function to compare nodes to given data which prints the data if it is NOT in the tree
void BinarySearchTree::compare_nodes(const std::string &str) {
    NodePtr node = m_root;
    NodePtr parent = nullptr;

    //search for the node to delete
    while (node != nullptr) {
        if (str < node->m_data) {
            //go left
            parent = node;
            node = node->m_left;
        } else if (str > node->m_data) {
            //go right
            parent = node;
            node = node->m_right;
        } else {
            //found the node
            return;
        }
    }
    std::cout << str << std::endl;

}

//overloaded operator function to output BST
std::ostream &operator<<(std::ostream &output, BinarySearchTree &bst) {
    bst.print(output, bst.m_root, 0);
    return output;
}

//Private insert function used in recursive call
void BinarySearchTree::insert(const std::string &str, NodePtr &node) {

    if (node == nullptr) {
        node = new Node();
        node->m_data = str;
    } else {
        if (str < node->m_data) {
            // Go left
            insert(str, node->m_left);
        } else if (str > node->m_data) {
            //Go right
            insert(str, node->m_right);
        } else {
            //Equal to
            std::cout << "Num is already inserted" << std::endl;
        }
    }
}

//Private Print function used for out to console and to print to file
void BinarySearchTree::print(std::ostream &output, NodePtr &node, int indent) {
    if (node != nullptr) {
        print(output, node->m_right, indent + 8);
        output << std::setw(indent) << node->m_data << std::endl;
        print(output, node->m_left, indent + 8);
    }
}

//Function used to print to file
void BinarySearchTree::print_to_file(BinarySearchTree tree, std::ofstream &file) {
    tree.print(file, tree.m_root, 0);
}
