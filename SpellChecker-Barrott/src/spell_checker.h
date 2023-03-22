//
// Created by barro on 2023-03-17.
//

#ifndef ASSIGNMENT_3_SPELL_CHECKER_H
#define ASSIGNMENT_3_SPELL_CHECKER_H

#include "binary_search_tree.h"


class SpellChecker {
public:
    void run_spell_checker(std::vector<std::string>, std::vector<std::string> test_v, std::string output);

    std::vector<std::string> open_file_to_vector(const std::string &input_file);

private:
    BinarySearchTree m_tree;

    void add_vector_to_tree(std::vector<std::string> v);

    void run_check(std::vector<std::string> test_v, const std::string &output_path);

};


#endif //ASSIGNMENT_3_SPELL_CHECKER_H
