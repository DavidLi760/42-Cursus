#include "Serializer.hpp"

int main() {
    Data data = {42, "Test Data"};

    std::cout << "ID: " << data.id << ", Name: " << data._name << std::endl;
    unsigned long raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << "\n" << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Deserialized pointer: " << deserializedData << "\n" << std::endl;
    std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->_name << std::endl;
    
    return 0;
}