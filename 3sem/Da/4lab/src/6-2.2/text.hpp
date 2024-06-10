#ifndef TEXT_HPP
#define TEXT_HPP

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Text {
public:
    struct Letter {
        int line, column, overlap;
        unsigned long long letter;

        Letter (string &letter, int line, int column) {
            this->letter = stoull(letter);
            this->line = line;
            this->column = column;
            this->overlap = 0;
        }

        ~Letter () {}
    };

    Text() : current_line(1), current_column(1) {}

    void Add_Letter(string &letter) {
        letters.push_back(new Letter(letter, this->current_line, this->current_column));
        this->Add_Column();
    }

    void Add_Line() {
        this->current_line += 1;
        this->current_column = 1;
    }

    void Add_Column() {
        this->current_column += 1;
    }

    int Size() {
        return this->letters.size();
    }

    ~Text() {
        for (Letter * letter : letters) {
            delete letter;
        }
    }

    int current_line;
    int current_column;
    vector <Letter *> letters;
};

#endif
