#include <iostream>
#include "Zoo.h"

int main() {
    Zoo zoo;

    // Load animals from file if exists
    zoo.loadFromFile();

    int choice;
    do {
        std::cout << "Zoo Management System\n";
        std::cout << "1. Add an animal\n";
        std::cout << "2. Remove an animal\n";
        std::cout << "3. Display all animals\n";
        std::cout << "4. Save animals to file\n";
        std::cout << "5. Load animals from file\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            // Add Animal
            std::string name, species;
            int age;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter age: ";
            std::cin >> age;
            std::cout << "Enter species: ";
            std::cin >> species;
            zoo.addAnimal(new Mammal(name, age, species)); // Adjust to allow different types
        } else if (choice == 2) {
            // Remove Animal
            int index;
            std::cout << "Enter index of animal to remove: ";
            std::cin >> index;
            zoo.removeAnimal(index);
        } else if (choice == 3) {
            // Display All Animals
            zoo.displayAllAnimals();
        } else if (choice == 4) {
            // Save Animals to File
            zoo.saveToFile();
        } else if (choice == 5) {
            // Load Animals from File
            zoo.loadFromFile();
        }

    } while (choice != 6);

    return 0;
}
