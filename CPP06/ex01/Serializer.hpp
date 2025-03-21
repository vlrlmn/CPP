# pragma once

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>


struct Data
{
    std::string name;
    int age;
    float height;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &obj); 
		Serializer &operator=(const Serializer &obj); 
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif