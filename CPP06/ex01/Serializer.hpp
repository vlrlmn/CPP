# pragma once

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

struct Data
{
    int         n;
    std::string s1;
    std::string s2;
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