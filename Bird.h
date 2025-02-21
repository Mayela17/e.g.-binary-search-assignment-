#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    Bird(std::string name, int age, std::string species) 
        : Animal(name, age, species) {}

    void makeSound() const override {
        std::cout << "The bird chirps.\n";
    }

    void displayInfo() const override {
        std::cout << "Bird Name: " << name << ", Age: " << age << ", Species: " << species << "\n";
    }
};

#endif // BIRD_H
