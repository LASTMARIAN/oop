#include <iostream>
#include <string>
#include <algorithm>

class Chef {
private:
    std::string chefName;

public:
    Chef(const std::string& name) : chefName(name) {
        std::cout << "Chef " << chefName << " created.\n";
    }

    ~Chef() {
        std::cout << "Chef " << chefName << " destroyed.\n";
    }

    std::string getName() const {
        std::cout << "Getting chef's name: " << chefName << "\n";
        return chefName;
    }

    int makeSalad(int ingredients) const {
        int portions = ingredients / 5;
        std::cout << "Making salad: " << portions << " portions from " << ingredients << " ingredients.\n";
        return portions;
    }

    int makeSoup(int ingredients) const {
        int portions = ingredients / 3;
        std::cout << "Making soup: " << portions << " portions from " << ingredients << " ingredients.\n";
        return portions;
    }
};

class ItalianChef : public Chef {
private:
    std::string password = "pizza";
    int flour = 0;
    int water = 0;

    bool makePizza() {
        int pizzas = std::min(flour / 5, water / 5);
        if (pizzas > 0) {
            std::cout << "Made " << pizzas << " pizzas!\n";
            flour -= pizzas * 5;
            water -= pizzas * 5;
            return true;
        } else {
            std::cout << "Not enough ingredients to make pizza.\n";
            return false;
        }
    }

public:
    ItalianChef(const std::string& name) : Chef(name) {
        std::cout << "ItalianChef " << getName() << " created.\n";
    }

    ~ItalianChef() {
        std::cout << "ItalianChef " << getName() << " destroyed.\n";
    }

    bool askSecret(const std::string& inputPassword, int inputFlour, int inputWater) {
        if (inputPassword == password) {
            flour = inputFlour;
            water = inputWater;
            std::cout << "Correct password. Attempting to make pizza with " 
                      << flour << " flour and " << water << " water.\n";
            return makePizza();
        } else {
            std::cout << "Incorrect password!\n";
            return false;
        }
    }
};