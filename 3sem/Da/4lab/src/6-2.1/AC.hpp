#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>


template <class K>
class TTrie {
    public:
        TTrie(): shift(0), count(0) {
            root = new TACNode<K>(-1);
        }

        void add(const K* key, size_t size) {
            if (size == 0) {
                return;
            }
            TACNode<K>* tmp = root;
            for(size_t i = 0; i < size; i++) {
                if (tmp->next.find(key[i]) == tmp->next.end()) {
                    tmp->next[key[i]] = new TACNode<K>;
                    tmp = tmp->next[key[i]];
                } else {
                    tmp = tmp->next[key[i]];
                }
            }
            tmp->shift.push_back(shift);
            shift += size;
            tmp->size = size;
            tmp->id = ++count;
        }
        void add(std::string key) {
            add(key.c_str(), key.size());
        }

        void addJoker() {
            ++shift;
        }

        size_t Size() {
            return shift;
        }

        size_t Count() {
            return count;
        }

        void link() {
            root->link();
        }

        void print() {
            std::cout << "root=" << size_t(root) << '\n';
            root->print(0);
        }
        ~TTrie(){
            delete root;
        }

        template <class KN>
        class TACNode {
            public:
                using map_pair = std::pair<TACNode<KN>* ,std::pair<KN, TACNode<KN>* >>;
                TACNode(): id(0), size(0), failLink(nullptr), outputLink(nullptr) {}
                TACNode(int id): id(id), size(0), failLink(nullptr), outputLink(nullptr) {}

                void link() {
                    std::queue<map_pair> wide;

                    for (std::pair<KN, TACNode<KN>*>  i: next) {
                        wide.push(map_pair(this, i));
                    }

                    TACNode<K>* tmp;
                    std::pair<KN, TACNode<KN>* > i;
                    while (!wide.empty()) {
                        i = wide.front().second;
                        tmp = wide.front().first;
                        if (tmp->id != -1) {
                            tmp = tmp->failLink;
                            while (1) {
                                if (tmp->next.find(i.first) == tmp->next.end()) {
                                    if (tmp->id == -1) {
                                        i.second->failLink = tmp;
                                        break;
                                    }
                                    tmp = tmp->failLink;
                                } else {
                                    i.second->failLink = tmp->next[i.first];
                                    if (i.second->failLink->id > 0) {
                                        i.second->outputLink = i.second->failLink;
                                    } else {
                                        i.second->outputLink = i.second->failLink->outputLink;
                                    }
                                    break;
                                }
                            }
                        } else {
                            i.second->failLink = tmp;
                        }
                        for (std::pair<KN, TACNode<KN>* > k: i.second->next) {
                            wide.push(map_pair(i.second, k));
                        }
                        wide.pop();
                    }
                }

                void print(int deep) {
                    for (std::pair<KN, TACNode<KN>*>  i: next) {
                        for (int k = 0; k < deep; k++) {
                            putchar('\t');
                        }
                        std::cout << i.first << ' ' << i.second->id
                                                    << " ptr=" << size_t(i.second)
                                                    << " fl->" << size_t(i.second->failLink)
                                                    << " ol->" << size_t(i.second->outputLink) << '\n';
                        (i.second)->print(deep + 1);
                    }
                }

                ~TACNode() {
                    for (std::pair<KN, TACNode<KN>*>  i: next) {
                        delete i.second;
                    }
                }

                long id;
                size_t size;
                std::vector<size_t> shift;
                std::unordered_map<KN, TACNode<KN>*> next;
                TACNode<KN>* failLink;
                TACNode<KN>* outputLink;
        };
        size_t shift;
        size_t count;
        TACNode<K>* root;
};
