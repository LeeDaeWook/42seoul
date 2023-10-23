template <typename T>
Array<T>::Array()
{
    std::cout << "Default Array constructor called" << std::endl;
    this->arr = new T[0];
    this->n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    std::cout << "Parameter Array constructor called" << std::endl;
    this->arr = new T[n];
    this->arr[0] = n;
    this->n = n;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Default Array destructor called" << std::endl;
    if (this->arr)
        delete[] this->arr;
}

template <typename T>
Array<T>::Array(const Array& array)
{
    std::cout << "Array Copy constructor called" << std::endl;
    *this = array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& array)
{
    std::cout << "Array Copy assignment operator called" << std::endl;
    if (this != &array) {
        this->n = array.n;
        this->arr = new T[this->n];
        this->arr[0] = this->n;
        for (unsigned int i = 0; i < this->n; i++)
            this->arr[i] = array.arr[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
    std::cout << "Array subscript assignment operator called" << std::endl;
    if (idx >= this->n) {
        throw std::exception();
    }
    return (this->arr[idx]);
}

template <typename T>
unsigned int Array<T>::size()
{
    return this->n;
}
