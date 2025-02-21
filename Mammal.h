#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

class Mammal : public Animal {
public:
    Mammal(std::string name, int age, std::string species) 
        : Animal(name, age, species) {}

    void makeSound() const override {
        std::cout << "The mammal makes a sound.\n";
    }

    void displayInfo() const override {
        std::cout << "Mammal Name: " << name << ", Age: " << age << ", Species: " << species << "\n";
    }
};

#endif // MAMMAL_H
