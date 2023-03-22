#include <iostream>
#include <vector>
#include <string>
#include "spell_checker.h"

using namespace std;

int main(int argc, char *argv[]) {
    SpellChecker checker;
    string input_path = argv[1];
    string input_path_two = argv[2];
    string output_path = argv[3];
    vector<string> v;
    vector<string> test_v;

    //Verify Input paths
    if (input_path.empty()) {
        cout << "Problem Opening dictionary File!";
        return 1;
    } else {
        v = checker.open_file_to_vector(input_path);
    }

    if (input_path_two.empty()) {
        cout << "Problem Opening File to test!";
        return 1;

    } else {
        test_v = checker.open_file_to_vector(input_path_two);
    }

    //Run the spell checker program.
    checker.run_spell_checker(v, test_v, output_path);

    return 0;
}