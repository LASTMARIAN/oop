#include <iostream>
#include <cstdlib>
#include <ctime>

int game(int maxnum) {
    std::srand(std::time(0));

    int etsittavaLuku = std::rand() % maxnum + 1;
    int arvaus;
    int arvaustenMaara = 0;

    std::cout << "Arvaa tietokoneen arpoma luku valilta 1-" << maxnum << ": ";

    do {
        std::cin >> arvaus;
        arvaustenMaara++;

        if (arvaus < etsittavaLuku) {
            std::cout << "Luku on suurempi. Yrita uudelleen: ";
        } else if (arvaus > etsittavaLuku) {
            std::cout << "Luku on pienempi. Yrita uudelleen: ";
        } else {
            std::cout << "Oikea vastaus! Luku oli " << etsittavaLuku << "." << std::endl;
        }
    } while (arvaus != etsittavaLuku);

    return arvaustenMaara;
}

int main() {
    int maxnum = 20;
    int arvaustenMaara = game(maxnum);
    std::cout << "Arvasit oikein " << arvaustenMaara << " yrityksella." << std::endl;
    return 0;
}

