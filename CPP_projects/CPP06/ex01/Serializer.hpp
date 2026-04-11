#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

struct Data
{
    int id;
    std::string _name;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        ~Serializer();
        Serializer& operator=(const Serializer& other);
    public:
        static unsigned long serialize(Data* ptr);
        static Data* deserialize(unsigned long raw);
};

#endif