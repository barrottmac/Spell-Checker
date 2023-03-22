//
// Created by barro on 2023-03-17.
//

#include <fstream>
#include <regex>
#include <iostream>
#include "spell_checker.h"

//This function adds a vector of words to a Binary search tree and balances it
void SpellChecker::add_vector_to_tree(std::vector<std::string> v) {
    for (int i = 0; i < v.size(); ++i) {
        m_tree.insert(v[i]);
    }
    m_tree.balance_tree();

}

//check test file against dictionary to see if the word is spelled correctly
void SpellChecker::run_check(std::vector<std::string> test_v, const std::string &output_path) {
    std::string regex_str = "[^a-zA-Z\\s]";
    std::regex rg(regex_str);
    std::ofstream output;
    output.open(output_path);

    //Iterate through test doc vector
    for (int i = 0; i < test_v.size(); ++i) {
        //add lines of test doc to string stream
        std::istringstream iss(test_v[i]);

        // Iterate the istringstream
        // using do-while loop
        do {
            std::string subs;

            // Get the word from the istringstream
            iss >> subs;
            std::string str = regex_replace(subs, rg, "");
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            m_tree.compare_nodes(str);

        } while (iss);
    }
    //If output file is open print the bst to file for viewing
    if (output.is_open()) {
        m_tree.print_to_file(m_tree, output);
    } else {
        std::cout << "Unable to open output file" << std::endl;
    }
}

//open an input file and add it line by line to a vector
std::vector<std::string> SpellChecker::open_file_to_vector(const std::string &input_file) {
    std::string line;
    std::vector<std::string> v;
    std::ifstream file;

    file.open(input_file);

    if (file.is_open()) {
        std::cout << "File Open" << std::endl;
        while (!file.eof()) {
            getline(file, line);
            v.push_back(line);
        }
    }
    return v;
}

//Public function to run the spell checker private functions
void SpellChecker::run_spell_checker(std::vector<std::string> v, std::vector<std::string>
test_v, std::string output_path) {
    add_vector_to_tree(v);
    run_check(test_v, output_path);
}
