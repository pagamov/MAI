#ifndef AHO_HPP
#define AHO_HPP

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#include "text.hpp"
#include "trie.hpp"

using namespace std;

class Korasic : Text, Trie {
public:
    Korasic () {}

    void Fill_Trie(vector <vector <string> > &patterns) {
        this->trie.Add_Word(patterns);
        this->trie.Link_Trie();
    }

    void Fill_Text(vector <vector <string> > &patterns) {
        for (vector <string> line : patterns) {
            for (string letter : line) {
                this->text.Add_Letter(letter);
            }
            this->text.Add_Line();
        }
    }

    void Overlap() {
        if (this->text.Size() != 0) {
            int current_position = 0;

            Node * current_node = this->trie.root;
            Node * ptr = nullptr;

            for (Letter * current_letter : this->text.letters) {
                while (true) {
                    if (current_node->ways.find(current_letter->letter) != current_node->ways.end()) {
                        current_node = current_node->ways[current_letter->letter];
                        break;
                    } else {
                        if (current_node->suff_link != nullptr) {
                            current_node = current_node->suff_link;
                        } else {
                            break;
                        }
                    }
                }
                if (this->trie.global_shift != -1) {
                    if (current_position - this->trie.global_shift >= 0) {
                        this->text.letters[current_position - this->trie.global_shift]->overlap += 1;
                        if (this->text.letters[current_position - this->trie.global_shift]->overlap == this->trie.word_counter + 1) {
                            cout << this->text.letters[current_position - this->trie.global_shift]->line << ", ";
                            cout << this->text.letters[current_position - this->trie.global_shift]->column << "\n";
                        }
                    }
                }

                if (current_node->leaf == true) {
                    for (int i : current_node->shift_back) {
                        if (current_position - i >= 0) {
                            this->text.letters[current_position - i]->overlap += 1;
                            if (this->text.letters[current_position - i]->overlap == this->trie.word_counter + 1) {
                                cout << this->text.letters[current_position - i]->line << ", ";
                                cout << this->text.letters[current_position - i]->column << "\n";
                            }
                        }
                    }
                }
                if (current_node->exit_link != nullptr) {
                    ptr = current_node->exit_link;
                    while (ptr != nullptr) {
                        if (ptr->leaf == true) {
                            for (int i : ptr->shift_back) {
                                if (current_position - i >= 0) {
                                    this->text.letters[current_position - i]->overlap += 1;
                                    if (this->text.letters[current_position - i]->overlap == this->trie.word_counter + 1) {
                                        cout << this->text.letters[current_position - i]->line << ", ";
                                        cout << this->text.letters[current_position - i]->column << "\n";
                                    }
                                }
                            }
                        }
                        ptr = ptr->exit_link;
                    }
                }
                ++current_position;
            }
        }
    }

    ~Korasic () {}

private:
    Text text;
    Trie trie;
};

#endif
