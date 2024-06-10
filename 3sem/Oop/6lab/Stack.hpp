#pragma once
#include <iterator>
#include <memory>

namespace containers {
	template <class T, class Allocator = std::allocator<T> >
	class Stack {
	private:
		struct element;
		size_t size = 0;
	public:
		Stack() = default;

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
			friend Stack;
		};

		forward_iterator begin();
		forward_iterator end();
		void push(const T& value);
		T& top();
		T& bottom();
		void pop();
		size_t length();
		void delete_by_it(forward_iterator d_it);
		void delete_by_index(size_t N);
		void insert_by_it(forward_iterator ins_it, T& value);
		void insert_by_index(size_t N, T& value);
		Stack& operator=(Stack& other);

	private:
		using allocator_type = typename Allocator::template rebind<element>::other;

		struct deleter {
			deleter(allocator_type* allocator) : allocator_(allocator) {}

			void operator() (element* ptr) {
				if (ptr != nullptr) {
					std::allocator_traits<allocator_type>::destroy(*allocator_, ptr);
					allocator_->deallocate(ptr, 1);
				}
			}

		private:
			allocator_type* allocator_;
		};

		using unique_ptr = std::unique_ptr<element, deleter>;
		unique_ptr push_impl(unique_ptr  cur, const T& value);
		unique_ptr pop_impl(unique_ptr cur);

		struct element {
			T value;
			unique_ptr next_element{ nullptr, deleter{nullptr} };
			element(const T& value_) : value(value_) {}
			forward_iterator next();
		};

		allocator_type allocator_{};
		unique_ptr first{ nullptr, deleter{nullptr} };
		element* tail = nullptr;
	};

	template<class T, class Allocator>
	typename Stack<T, Allocator>::forward_iterator Stack<T, Allocator>::begin() {
		return forward_iterator(first.get());
	}

	template<class T, class Allocator>
	typename Stack<T, Allocator>::forward_iterator Stack<T, Allocator>::end() {
		return forward_iterator(nullptr);
	}

	template<class T, class Allocator>
	size_t Stack<T, Allocator>::length() {
		return size;
	}

	template<class T, class Allocator>
	void Stack<T,  Allocator>::push(const T& value) {
		first = push_impl(std::move(first), value);
		size++;
	}

	template<class T, class Allocator>
	typename Stack<T, Allocator>::unique_ptr Stack<T, Allocator>::push_impl(unique_ptr cur, const T& value) {
		if (cur != nullptr) {
			cur->next_element = push_impl(std::move(cur->next_element), value);
			return cur;
		}
		element* result = this->allocator_.allocate(1);
		std::allocator_traits<allocator_type>::construct(this->allocator_, result, value);
		return unique_ptr(result, deleter{&this->allocator_});
	}


	template<class T, class Allocator>
	void Stack<T, Allocator>::pop() {
		if (size == 0) {
			throw std::logic_error("Stack is empty");
		}
		first = pop_impl(std::move(first));
		size--;
	}


	template<class T, class Allocator>
	typename Stack<T, Allocator>::unique_ptr Stack<T, Allocator>::pop_impl(unique_ptr cur) {
		if (cur->next_element != nullptr) {
			cur->next_element = pop_impl(std::move(cur->next_element));
			return cur;
		}
		return unique_ptr(nullptr, deleter{ &this->allocator_ });//?
	}

	template<class T, class Allocator>
	T& Stack<T, Allocator>::top() {
		if (size == 0) {
			throw std::logic_error("Stack is empty");
		}
		forward_iterator i = this->begin();
		while (i.it_ptr->next() != this->end()) {
			i++;
		}
		return *i;
	}

	template<class T, class Allocator>
	T& Stack<T, Allocator>::bottom() {
		return first->value;
	}

	template<class T, class Allocator>
	Stack<T, Allocator>& Stack<T, Allocator>::operator=(Stack<T, Allocator>& other) {
		size = other.size;
		first = std::move(other.first);
	}

	template<class T, class Allocator>
	void Stack<T, Allocator>::delete_by_it(containers::Stack<T, Allocator>::forward_iterator d_it) {
		forward_iterator i = this->begin(), end = this->end();
		if (d_it == end) {
			throw std::logic_error("out of borders");
		}
		if (d_it == this->begin()) {
			auto tmp = std::move(first->next_element);
			first = std::move(tmp);
			return;
		}
		while ((i.it_ptr != nullptr) && (i.it_ptr->next() != d_it)) {
			++i;
		}
		if (i.it_ptr == nullptr) throw std::logic_error("out of borders");
		i.it_ptr->next_element = std::move(d_it.it_ptr->next_element);
		size--;
	}

	template<class T, class Allocator>
	void Stack<T, Allocator>::delete_by_index(size_t N) {
		forward_iterator it = this->begin();
		for (size_t i = 0; i < N; ++i) {
			++it;
		}
		this->delete_by_it(it);
	}

	template<class T, class Allocator>
	void Stack<T, Allocator>::insert_by_it(containers::Stack<T, Allocator>::forward_iterator ins_it, T& value) {
		forward_iterator i = this->begin();
		if (ins_it == this->end()) {
			this->push(value);
			return;
		}
		element* tmp = this->allocator_.allocate(1);
		std::allocator_traits<allocator_type>::construct(this->allocator_, tmp, value);
		if (ins_it == this->begin()) {
			tmp->next_element = std::move(first);
			first = unique_ptr(tmp, deleter{ &this->allocator_ });
			size++;
			return;
		}
		while ((i.it_ptr != nullptr) && (i.it_ptr->next() != ins_it)) {
			++i;
		}
		if (i.it_ptr == nullptr) throw std::logic_error("out of borders");
		tmp->next_element = std::move(i.it_ptr->next_element);
		i.it_ptr->next_element = unique_ptr(tmp, deleter{ &this->allocator_ });
		size++;
	}

	template<class T, class Allocator>
	void Stack<T, Allocator>::insert_by_index(size_t N, T& value) {
		forward_iterator it = this->begin();
		if (N >= this->length())
			it = this->end();
		else
			for (size_t i = 1; i <= N; ++i) {
				++it;
			}
		this->insert_by_it(it, value);
	}

	template<class T, class Allocator>
	typename Stack<T, Allocator>::forward_iterator Stack<T, Allocator>::element::next() {
		return forward_iterator(this->next_element.get());
	}

	template<class T, class Allocator>
	Stack<T, Allocator>::forward_iterator::forward_iterator(containers::Stack<T, Allocator>::element* ptr) {
		it_ptr = ptr;
	}

	template<class T, class Allocator>
	T& Stack<T, Allocator>::forward_iterator::operator*() {
		return this->it_ptr->value;
	}

	template<class T, class Allocator>
	typename Stack<T, Allocator>::forward_iterator& Stack<T, Allocator>::forward_iterator::operator++() {
		if (it_ptr == nullptr) throw std::logic_error("out of Stack");
		*this = it_ptr->next();
		return *this;
	}

	template<class T, class Allocator>
	typename Stack<T, Allocator>::forward_iterator Stack<T, Allocator>::forward_iterator::operator++(int) {
		forward_iterator old = *this;
		++* this;
		return old;
	}

	template<class T, class Allocator>
	bool Stack<T, Allocator>::forward_iterator::operator==(const forward_iterator& other) const {
		return it_ptr == other.it_ptr;
	}
	template<class T, class Allocator>
	bool Stack<T, Allocator>::forward_iterator::operator!=(const forward_iterator& other) const {
		return it_ptr != other.it_ptr;
	}

}
