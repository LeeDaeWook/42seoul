#ifndef __MutantStack_HPP__
# define __MutantStack_HPP__
# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(MutantStack &mutantStack) {*this = mutantStack;};
        MutantStack& operator=(MutantStack& mutantStack) {
            if (this != &mutantStack) {
                std::stack<T>::operator=(mutantStack);
            }
            return *this;
        };

        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin() {return this->c.begin();};
        iterator end() {return this->c.end();};

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() {return this->c.rbegin();};
        reverse_iterator rend() {return this->c.rend();};
};

#endif



// template <typename T>
// struct Node {
//     T data; 
//     Node<T> *next;
//     Node<T> *prev;
// };

// template <typename T>
// class Iterator {
//     private:
//         Node<T> *cur;

//     public:
//         Iterator();
//         Iterator(Node<T> *ptr);
//         ~Iterator();
//         Iterator(Iterator &iterator);
//         Iterator &operator=(Iterator& iterator);

//         Iterator& operator++();
//         Iterator& operator--();
//         T& operator*();
//         bool operator==(const Iterator& iterator);
//         bool operator!=(const Iterator& iterator);

//         void setCur(Node<T> *ptr);
// };

// template <typename T>
// class MutantStack : public std::stack<T> {
//     private:
//         Node<T> *head;
//         int stackSize;
//         Iterator<T>* itBegin;
//         Iterator<T>* itEnd;

//     public:
//         MutantStack();
//         ~MutantStack();
//         MutantStack(MutantStack &mutantStack);
//         MutantStack &operator=(MutantStack& mutantStack);

//         void deleteStack();
//         void copyStack(MutantStack &mutantStack);

//         void push(T data);
//         void pop();
//         T top();
//         unsigned int size();
//         bool empty();
        
//         typedef Iterator<T> iterator;
//         iterator& begin();

//         // iterator& begin() {
//         //     std::cout << "MutantStack begin() called" << std::endl;
//         //     itBegin->setCur(head);
//         //     return *itBegin;
//         // }

//         iterator& end() {
//             std::cout << "MutantStack end() called" << std::endl;
//             return *itEnd;
//         }
// };

// # include "MutantStack.tpp"

