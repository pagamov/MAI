#ifndef STACK_H
#define STACK_H

#include <iterator>
#include <memory>
#include <algorithm>

namespace containers {
    template<class T>
    class stack {
    private:
        struct element;
        size_t size = 0;
    public:
        stack() = default;

        class forward_iterator {
        public:
            using value_type = T;
            using reference = T&;
            using pointer = T*;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::forward_iterator_tag;
            explicit forward_iterator(element* ptr);
            T& operator*();
            forward_iterator& operator++();
            forward_iterator operator++(int);
            bool operator== (const forward_iterator& other) const;
            bool operator!= (const forward_iterator& other) const;
        private:
            element* it_ptr;
            friend stack;
        };

        forward_iterator begin();
        forward_iterator end();
        void push(const T& value);
        T& top();
        void pop();
        void delete_by_it(forward_iterator d_it);
        void delete_by_number(size_t N);
        void insert_by_it(forward_iterator ins_it, T& value);
        void insert_by_number(size_t N, T& value);
    private:
        struct element {
            T value;
            std::unique_ptr<element> next_element = nullptr;
            forward_iterator next();
        };
        std::unique_ptr<element> first = nullptr;
    };

    template<class T>
    typename stack<T>::forward_iterator stack<T>::begin() {
        return forward_iterator(first.get());
    }

    template<class T>
    typename stack<T>::forward_iterator stack<T>::end() {
        return forward_iterator(nullptr);
    }

    template<class T>
    void stack<T>::push(const T& value) {
        if (first == nullptr){
            first = std::unique_ptr<element>(new element{value});
        }else{
            auto *tmp = new element{value};
            std::swap(tmp->next_element, first);
            first = std::move(std::unique_ptr<element>(tmp));
        }
        size++;
    }

    template<class T>
    void stack<T>::pop() {
        if (size == 0) {
            throw std::logic_error ("stack is empty");
        }
        first = std::move(first->next_element);
        size--;
    }

    template<class T>
    T& stack<T>::top() {
        if (size == 0) {
            throw std::logic_error ("stack is empty");
        }
        return first->value;
    }

    template<class T>
    void stack<T>::delete_by_it(containers::stack<T>::forward_iterator d_it) {
        forward_iterator i = this->begin(), end = this->end();
        if (d_it == end) throw std::logic_error ("out of borders");
        if (d_it == this->begin()) {
            this->pop();
            return;
        }
        while((i.it_ptr != nullptr) && (i.it_ptr->next() != d_it)) { ++i; }
        if (i.it_ptr == nullptr) throw std::logic_error ("out of borders");
        i.it_ptr->next_element = std::move(d_it.it_ptr->next_element);
        size--;
    }

    template<class T>
    void stack<T>::delete_by_number(size_t N) {
        forward_iterator it = this->begin();
        for (size_t i = 1; i <= N; ++i) {
            if (i == N) break;
            ++it;
        }
        this->delete_by_it(it);
    }

    template<class T>
    void stack<T>::insert_by_it(containers::stack<T>::forward_iterator ins_it, T& value) {
        auto tmp = std::unique_ptr<element>(new element{value});
        forward_iterator i = this->begin();
        if (ins_it == this->begin()) {
            tmp->next_element = std::move(first);
            first = std::move(tmp);
            size++;
            return;
        }
        while((i.it_ptr != nullptr) && (i.it_ptr->next() != ins_it)) {
            ++i;
        }
        if (i.it_ptr == nullptr) throw std::logic_error ("out of borders");
        tmp->next_element = std::move(i.it_ptr->next_element);
        i.it_ptr->next_element = std::move(tmp);
        size++;
    }

    template<class T>
    void stack<T>::insert_by_number(size_t N, T& value) {
        forward_iterator it = this->begin();
        for (size_t i = 1; i <= N; ++i) {
            if (i == N) break;
            ++it;
        }
        this->insert_by_it(it, value);
    }

    template<class T>
    typename stack<T>::forward_iterator stack<T>::element::next() {
        return forward_iterator(this->next_element.get());
    }

    template<class T>
    stack<T>::forward_iterator::forward_iterator(containers::stack<T>::element *ptr) {
        it_ptr = ptr;
    }

    template<class T>
    T& stack<T>::forward_iterator::operator*() {
        return this->it_ptr->value;
    }

    template<class T>
    typename stack<T>::forward_iterator& stack<T>::forward_iterator::operator++() {
        if (it_ptr == nullptr) throw std::logic_error ("out of stack borders");
        *this = it_ptr->next();
        return *this;
    }

    template<class T>
    typename stack<T>::forward_iterator stack<T>::forward_iterator::operator++(int) {
        forward_iterator old = *this;
        ++*this;
        return old;
    }

    template<class T>
    bool stack<T>::forward_iterator::operator==(const forward_iterator& other) const {
        return it_ptr == other.it_ptr;
    }

    template<class T>
    bool stack<T>::forward_iterator::operator!=(const forward_iterator& other) const {
        return it_ptr != other.it_ptr;
    }
}
#endif
