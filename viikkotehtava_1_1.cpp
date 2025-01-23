#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    int etsittavaLuku = std::rand() % 20 + 1;
    int arvaus;

    std::cout << "Arvaa tietokoneen arpoma luku valilta 1-20: ";

    do {
        std::cin >> arvaus;

        if (arvaus < etsittavaLuku) {
            std::cout << "Luku on suurempi. Yrita uudelleen: ";
        } else if (arvaus > etsittavaLuku) {
            std::cout << "Luku on pienempi. Yrita uudelleen: ";
        } else {
            std::cout << "Oikea vastaus! Luku oli " << etsittavaLuku << "." << std::endl;
        }
    } while (arvaus != etsittavaLuku);

    return 0;
}
