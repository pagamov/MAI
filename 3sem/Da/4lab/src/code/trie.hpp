#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Trie {
public:
    Trie () : global_shift(-1) {
        root = new Node();
    }

    void Add_Word(vector <vector <string> > &patterns) {
        for (vector <string> word : patterns) {
            if (word[0] != "?") {
                root->Add_Word(word, this->global_shift);
                this->word_counter += 1;
            }
            this->global_shift += word.size();
        }
    }

    void Link_Trie() {
        for (pair <string, Node *> word : root->ways) {
            word.second->Link_S();
        }
        for (pair <string, Node *> word : root->ways) {
            word.second->Link_E();
        }
    }

    ~Trie () {
        delete root;
    }

    struct Node {
        unordered_map <string, Node *> ways;
        bool leaf;
        Node * parent;
        Node * suff_link;
        Node * exit_link;
        string pch;
        vector <int> shift_back;

        Node() : leaf(false), parent(nullptr), suff_link(nullptr), exit_link(nullptr) {}

        void Add_Word(vector <string> &word, int global_shift, int position = 0) {
            if (int(word.size()) == position) {
                leaf = true;
                this->shift_back.push_back(word.size() + global_shift);
                return;
            }
            for (int i = 0; i < int(word[position].size()); i++) {
                if (word[position][i] >= 'A' && word[position][i] <= 'Z') {
                    word[position][i] = 'a' + (word[position][i] - 'A');
                }
            }
            if (ways.find(word[position]) == ways.end()) {
                ways[word[position]] = new Node();
                ways[word[position]]->parent = this;
                ways[word[position]]->pch = word[position];
            }
            ways[word[position]]->Add_Word(word, global_shift, position + 1);
        }

        void Link_Suff() {
            if (this->suff_link == nullptr) {
                Node * Parent = this->parent;
                if (Parent->suff_link == nullptr && Parent->parent != nullptr) {
                    Parent->Link_Suff();
                } else if (Parent->parent == nullptr) {
                    this->suff_link = Parent;
                    return;
                }
                Node * suff = Parent->suff_link;
                while (true) {
                    if (suff->ways.find(this->pch) != suff->ways.end()) {
                        this->suff_link = suff->ways[this->pch];
                        return;
                    }
                    if (suff->suff_link == nullptr && suff->parent != nullptr) {
                        suff->Link_Suff();
                    } else if (suff->parent == nullptr) {
                        this->suff_link = suff;
                        return;
                    }
                    suff = suff->suff_link;
                }
            }
        }

        void Link_S() {
            for (pair <string, Node *> word : ways) {
                word.second->Link_S();
            }
            this->Link_Suff();
        }

        void Link_Exit() {
            Node * suff = this->suff_link;
            while (true) {
                if (suff->leaf == true) {
                    this->exit_link = suff;
                    return;
                } else if (suff->parent == nullptr) {
                    return;
                }
                suff = suff->suff_link;
            }
        }

        void Link_E() {
            for (pair <string, Node *> word : ways) {
                word.second->Link_E();
            }
            this->Link_Exit();
        }

        ~Node() {
            for (pair <string, Node *> word : ways) {
                delete word.second;
            }
        }
    };

    Node * root;
    int global_shift;
    int word_counter;
};

#endif
