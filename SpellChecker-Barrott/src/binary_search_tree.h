//
// Created by barro on 2023-03-14.
//

#ifndef ASSIGNMENT_3_BINARY_SEARCH_TREE_H
#define ASSIGNMENT_3_BINARY_SEARCH_TREE_H

#include <ostream>
#include <vector>

struct Node;

using NodePtr = Node *;

struct Node {
    std::string m_data{-1};
    NodePtr m_left{nullptr};
    NodePtr m_right{nullptr};
};

class BinarySearchTree {
private:
    NodePtr m_root{nullptr};


public:

    void insert(const std::string &str);

    void compare_nodes(const std::string &str);

    void balance_tree();

    friend std::ostream &operator<<(std::ostream &output, BinarySearchTree &bst);

    friend std::ofstream &operator<<(std::ofstream &output, BinarySearchTree &bst);

    void print_to_file(BinarySearchTree tree, std::ofstream &file);


private:

    void insert(const std::string &str, NodePtr &node);

    void print(std::ostream &output, NodePtr &node, int indent);

    void store_bst_nodes(NodePtr root, std::vector<NodePtr> &nodes);

    NodePtr build_tree_util(std::vector<NodePtr> &nodes, int start, int end);

    NodePtr build_tree(NodePtr root);

};


#endif //ASSIGNMENT_3_BINARY_SEARCH_TREE_H
