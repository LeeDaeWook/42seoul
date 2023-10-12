#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__
# include <iostream>
# include <string>

typedef struct s_data {
    int data;
}   Data;

class Serializer {
    public:
        Serializer();
        virtual ~Serializer();
        Serializer(const Serializer& serializer);
        Serializer& operator=(const Serializer& serializer);

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif