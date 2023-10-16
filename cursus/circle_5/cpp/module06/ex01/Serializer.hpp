#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__
# include <iostream>
# include <string>

typedef struct s_data {
    int data;
}   Data;

class Serializer {
    private:
        Serializer();
        virtual ~Serializer();
        Serializer(const Serializer& serializer);
        Serializer& operator=(const Serializer& serializer);
    
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif