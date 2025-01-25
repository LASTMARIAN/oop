#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
    private:
        int maxNumber;
        int playerGuess;
        int randomNumber;
        int numOfGuesses;
    public:
        Game(int maxNumber) : maxNumber(maxNumber) {
            std::cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value";
            play();
        }
        ~Game() {
            std::cout << "GAME DESTRUCTOR: object cleared from stack memory";
        }
        void play() {
            randomNumber = std::rand() % maxNumber + 1;
            numOfGuesses = 0;

            std::cout << "Arvaa tietokoneen arpoma luku valilta 1-" << maxNumber << ": ";

            do {
                std::cin >> playerGuess;
                numOfGuesses++;

                if (playerGuess < randomNumber) {
                    std::cout << "Luku on suurempi. Yrita uudelleen: ";
                } else if (playerGuess > randomNumber) {
                    std::cout << "Luku on pienempi. Yrita uudelleen: ";
                } else {
                    std::cout << "Oikea vastaus! Luku oli " << randomNumber << "." << std::endl;
                }
            } while (playerGuess != randomNumber);
            std::cout << "Arvasit oikein " << numOfGuesses << " yrityksella." << std::endl;
        };
};

int main() {
    Game game1(20);
    return 0;
}

