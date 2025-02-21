#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Animal class representing different animal types
class Animal {
public:
    string species;
    int age;
    string health_status;
    string special_characteristics;

    // Virtual function for animal specific behaviors
    virtual void eat() {
        cout << "Animal eats." << endl;
    }

    // Overloaded operators for comparison
    bool operator<(const Animal& other) const {
        return age < other.age;
    }
    bool operator==(const Animal& other) const {
        return species == other.species && age == other.age;
    }
};

// Zoo class managing the virtual zoo
class Zoo {
public:
    string name;
    vector<Animal> animals;

    // Add a new animal to the zoo
    void addAnimal(Animal animal) {
        animals.push_back(animal);
    }

    // Remove an animal from the zoo
    void removeAnimal(Animal animal) {
        for (int i = 0; i < animals.size(); i++) {
            if (animals[i] == animal) {
                animals.erase(animals.begin() + i);
                break;
            }
        }
    }

    // Simulate feeding animals
    void feedAnimals() {
        for (Animal animal : animals) {
            animal.eat();
        }
    }
};

// Base employee class
class Employee {
public:
    string name;
    string role;

    // Virtual function for specific employee tasks
    virtual void doTask() {
        cout << "Employee performs a task." << endl;
    }
};

// Zookeeper derived from employee
class Zookeeper : public Employee {
public:
    // Specific task for zookeeper
    void cleanAnimalEnclosure() {
        cout << "Zookeeper cleans animal enclosure." << endl;
    }
};

// Veterinarian derived from employee
class Veterinarian : public Employee {
public:
    // Specific task for veterinarian
    void checkAnimalHealth(Animal animal) {
        cout << "Veterinarian checks animal health." << endl;
    }
};

// Enumeration for employee roles
enum Role {
    ZOO_KEEPER,
    VETERINARIAN
};

int main() {
    // Create a new zoo
    Zoo zoo;
    zoo.name = "My Virtual Zoo";

    // Add some animals
    Animal lion;
    lion.species = "Lion";
    lion.age = 5;
    lion.health_status = "Healthy";
    lion.special_characteristics = "Maned predator";
    zoo.addAnimal(lion);

    Animal zebra;
    zebra.species = "Zebra";
    zebra.age = 2;
    zebra.health_status = "Good";
    zebra.special_characteristics = "Striped herbivore";
    zoo.addAnimal(zebra);

    // Create and assign employees
    Zookeeper john;
    john.name = "John Smith";
    john.role = "Zookeeper";

    Veterinarian jane;
    jane.name = "Jane Doe";
    jane.role = "Veterinarian";

    // Simulate day-to-day operations
    zoo.feedAnimals();
    john.cleanAnimalEnclosure();
    jane.checkAnimalHealth(lion);

    // Access animal information
    cout << "Lion species: " << lion.species << endl;
    cout << "Zebra age: " << zebra.age << endl;

    // Remove an animal
    zoo.removeAnimal(zebra);

    return 0;
