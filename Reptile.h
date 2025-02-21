#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"

class Reptile : public Animal {
public:
    Reptile(std::string name, int age, std::string species) 
        : Animal(name, age, species) {}

    void makeSound() const override {
        std::cout << "The reptile hisses.\n";
    }

    void displayInfo() const override {
        std::cout << "Reptile Name: " << name << ", Age: " << age << ", Species: " << species << "\n";
    }
};

#endif // REPTILE_H
