#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "korasic.hpp"

using namespace std;

enum States {
    WORD,
    JOKER,
    START
};

string line;
string letter;
vector <string> pattern;
vector <vector <string> > patterns;

Korasic korasic;

int main(int argc, char ** argv) {
    States state = START;

    getline(cin, line);
    std::istringstream iline(line);

    while (iline >> letter) {
        if (letter == "?") {
            switch (state) {
                case WORD:
                    patterns.push_back(pattern);
                    pattern.clear();
                    state = JOKER;
                    break;
                case START:
                    state = JOKER;
                    break;
                case JOKER:
                    break;
            }
            pattern.push_back(letter);
        } else {
            switch (state) {
                case JOKER:
                    patterns.push_back(pattern);
                    pattern.clear();
                    state = WORD;
                    break;
                case START:
                    state = WORD;
                    break;
                case WORD:
                    break;
            }
            pattern.push_back(letter);
        }
    }
    switch (state) {
        case WORD:
        case JOKER:
            patterns.push_back(pattern);
            break;
        case START:
            break;
    }

    korasic.Fill_Trie(patterns);

    pattern.clear();
    patterns.clear();

    while(getline(cin, line)) {
        std::istringstream iline(line);
        while (iline >> letter) {
            pattern.push_back(letter);
        }
        patterns.push_back(pattern);
        pattern.clear();
    }

    korasic.Fill_Text(patterns);

    korasic.Overlap();
    return 0;
}
