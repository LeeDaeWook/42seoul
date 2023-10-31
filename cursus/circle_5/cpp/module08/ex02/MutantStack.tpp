#include "MutantStack.hpp"

template <typename T>
Iterator<T>::Iterator() : cur(NULL)
{
    std::cout << "Default Iterator constructor called" << std::endl;
}

template <typename T>
Iterator<T>::Iterator(Node<T> *ptr) : cur(ptr)
{
    std::cout << "Parameter Iterator constructor called" << std::endl;
}

template <typename T>
Iterator<T>::~Iterator()
{
    std::cout << "Default Iterator destructor called" << std::endl;
}

template <typename T>
Iterator<T>::Iterator(Iterator &iterator)
{
    std::cout << "Iterator Copy constructor called" << std::endl;
    *this = iterator;
}

template <typename T>
Iterator<T> &Iterator<T>::operator=(Iterator &iterator)
{
    std::cout << "Iterator Copy assignment operator called" << std::endl;

    if (this != &iterator)
    {
        cur = iterator.cur;
    }
    return *this;
}

template <typename T>
Iterator<T> &Iterator<T>::operator++()
{
    std::cout << "Iterator ++ operator called" << std::endl;
    cur = cur->next;
    return *this;
}

template <typename T>
Iterator<T> &Iterator<T>::operator--()
{
    std::cout << "Iterator -- operator called" << std::endl;
    cur = cur->prev;
    return *this;
}

template <typename T>
T &Iterator<T>::operator*()
{
    std::cout << "Iterator * operator called" << std::endl;
    return cur->data;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator &iterator)
{
    std::cout << "Iterator == operator called" << std::endl;
    return cur == iterator.cur;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator &iterator)
{
    std::cout << "Iterator != operator called" << std::endl;
    return cur != iterator.cur;
}












template <typename T>
MutantStack<T>::MutantStack() : head(NULL), stackSize(0)
{
    // std::cout << "Default MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    // std::cout << "Default MutantStack destructor called" << std::endl;
    deleteStack();
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack &mutantStack) : head(NULL), stackSize(0)
{
    // std::cout << "MutantStack Copy constructor called" << std::endl;
    *this = mutantStack;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack &mutantStack)
{
    // std::cout << "MutantStack Copy assignment operator called" << std::endl;

    if (this != &mutantStack)
    {
        if (head)
            deleteStack();
        copyStack(mutantStack);
        stackSize = mutantStack.stackSize;
    }
    return *this;
}

template <typename T>
void MutantStack<T>::deleteStack()
{
    // std::cout << "MutantStack deleteStack() called" << std::endl;
    Node<T> *tmp = head;
    while (tmp)
    {
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
}

template <typename T>
void MutantStack<T>::copyStack(MutantStack &mutantStack)
{
    // std::cout << "MutantStack copyStack() called" << std::endl;
    Node<T> *bottom = mutantStack.head;
    for (int i = 0; i < mutantStack.stackSize - 1; i++)
        bottom = bottom->next;
    
    Node<T> *newNode = new Node<T>;
    newNode->data = bottom->data;
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    bottom = bottom->prev;
    while (bottom)
    {
        newNode = new Node<T>;
        newNode->data = bottom->data;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        bottom = bottom->prev;
    }
}

template <typename T>
void MutantStack<T>::push(T data)
{
    // std::cout << "MutantStack push() called" << std::endl;
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = head;
    if (head)
        head->prev = newNode;
    head = newNode;
    stackSize++;
}

template <typename T>
void MutantStack<T>::pop()
{
    // std::cout << "MutantStack pop() called" << std::endl;
    Node<T> *tmp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    delete tmp;
    stackSize--;
}

template <typename T>
T MutantStack<T>::top()
{
    // std::cout << "MutantStack top() called" << std::endl;
    return head->data;
}

template <typename T>
unsigned int MutantStack<T>::size()
{
    // std::cout << "MutantStack size() called" << std::endl;
    return stackSize;
}

template <typename T>
bool MutantStack<T>::empty()
{
    // std::cout << "MutantStack empty() called" << std::endl;
    return stackSize == 0;
}
