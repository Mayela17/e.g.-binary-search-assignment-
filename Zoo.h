#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include <iostream>
#include <fstream>

class Zoo {
private:
    Animal** animals;
    int numAnimals;
    int maxAnimals;

    void resizeArray() {
        maxAnimals *= 2;
        Animal** newArray = new Animal*[maxAnimals];
        for (int i = 0; i < numAnimals; ++i) {
            newArray[i] = animals[i];
        }
        delete[] animals;
        animals = newArray;
    }

public:
    Zoo() : numAnimals(0), maxAnimals(5) {
        animals = new Animal*[maxAnimals];
    }

    ~Zoo() {
        for (int i = 0; i < numAnimals; ++i) {
            delete animals[i];
        }
        delete[] animals;
    }

    void addAnimal(Animal* animal) {
        if (numAnimals >= maxAnimals) {
            resizeArray();
        }
        animals[numAnimals++] = animal;
    }

    void removeAnimal(int index) {
        if (index >= 0 && index < numAnimals) {
            delete animals[index];
            for (int i = index; i < numAnimals - 1; ++i) {
                animals[i] = animals[i + 1];
            }
            --numAnimals;
        }
    }

    void displayAllAnimals() const {
        for (int i = 0; i < numAnimals; ++i) {
            animals[i]->displayInfo();
        }
    }

    void saveToFile() const {
        std::ofstream file("zoo_data.txt");
        for (int i = 0; i < numAnimals; ++i) {
            file << animals[i]->getName() << "," << animals[i]->getAge() << "," << animals[i]->getSpecies() << "\n";
        }
        file.close();
    }

    void loadFromFile() {
        std::ifstream file("zoo_data.txt");
        std::string name, species;
        int age;
        while (file >> name >> age >> species) {
            addAnimal(new Mammal(name, age, species)); // Change to handle correct type
        }
        file.close();
    }

    int getNumAnimals() const {
        return numAnimals;
    }

    Animal* getAnimal(int index) const {
        return animals[index];
    }
};

#endif // ZOO_H
