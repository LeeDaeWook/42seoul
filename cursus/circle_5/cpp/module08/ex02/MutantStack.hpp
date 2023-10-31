#ifndef __MutantStack_HPP__
# define __MutantStack_HPP__
# include <iostream>
# include <string>

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template <typename T>
class Iterator {
    private:
        Node<T> *cur;

    public:
        Iterator();
        Iterator(Node<T> *ptr);
        ~Iterator();
        Iterator(Iterator &iterator);
        Iterator &operator=(Iterator& iterator);

        Iterator& operator++();
        Iterator& operator--();
        T& operator*();
        bool operator==(const Iterator& iterator);
        bool operator!=(const Iterator& iterator);
};

template <typename T>
class MutantStack {
    private:
        Node<T> *head;
        int stackSize;

    public:
        MutantStack();
        ~MutantStack();
        MutantStack(MutantStack &mutantStack);
        MutantStack &operator=(MutantStack& mutantStack);

        void deleteStack();
        void copyStack(MutantStack &mutantStack);

        void push(T data);
        void pop();
        T top();
        unsigned int size();
        bool empty();
        
        typedef Iterator<T> iterator;

        iterator begin() {
            std::cout << "MutantStack begin() called" << std::endl;
            return iterator(head);
        }

        iterator end() {
            std::cout << "MutantStack end() called" << std::endl;
            return iterator(NULL);
        }
};

# include "MutantStack.tpp"

#endif