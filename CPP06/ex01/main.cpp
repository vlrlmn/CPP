#include "Serializer.hpp"

int main() {
    Data original;
    original.name = "Alice";
    original.age = 25;
    original.height = 1.68f;

    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << original.name << std::endl;
    std::cout << "Age: " << original.age << std::endl;
    std::cout << "Height: " << original.height << std::endl;
    std::cout << "Original Address: " << &original << std::endl;

    // Serialize
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "\nSerialized uintptr_t: " << raw << std::endl;

    // Deserialize
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Height: " << deserialized->height << std::endl;
    std::cout << "Deserialized Address: " << deserialized << std::endl;

    //Adress coinsice
    if (deserialized == &original) {
        std::cout << "Deserialization successful! Addresses match." << std::endl;
    } else {
        std::cout << std::endl << "Deserialization failed! Addresses do not match." << std::endl;
    }

    return 0;
}
