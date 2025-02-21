#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
protected:
    std::string name;
    int age;
    std::string species;

public:
    // Constructor
    Animal(std::string name, int age, std::string species) 
        : name(name), age(age), species(species) {}

    virtual ~Animal() {}

    // Pure virtual functions
    virtual void makeSound() const = 0;
    virtual void displayInfo() const = 0;
};

#endif // ANIMAL_H
