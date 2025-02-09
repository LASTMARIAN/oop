#include <iostream>
#include <string>

class Seuraaja {
public:
    std::string nimi;
    Seuraaja* next;

    Seuraaja(std::string name) : nimi(name), next(nullptr) {
        std::cout << "Luodaan seuraaja " << name << std::endl;
    }

    void paivita(const std::string& viesti) {
        std::cout << nimi << " sai viestin: " << viesti << std::endl;
    }
};

class Notifikaattori {
private:
    Seuraaja* seuraajat;

public:
    Notifikaattori() : seuraajat(nullptr) {
        std::cout << "Luodaan notifikaattori" << std::endl;
    }

    void lisaa(const std::string& name) {
        Seuraaja* uusi = new Seuraaja(name);
        uusi->next = seuraajat;
        seuraajat = uusi;
        std::cout << "Lisätään seuraaja " << name << std::endl;
    }

    void poista(const std::string& name) {
        Seuraaja* current = seuraajat;
        Seuraaja* previous = nullptr;

        
        while (current != nullptr) {
            if (current->nimi == name) {
                if (previous == nullptr) {
                    seuraajat = current->next;
                } else {
                    previous->next = current->next;
                }
                std::cout << "Poistetaan " << name << std::endl;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void tulosta() {
        Seuraaja* current = seuraajat;
        while (current != nullptr) {
            std::cout << "Seuraaja" << current->nimi << std::endl;
            current = current->next;
        }
    }

    void postita(const std::string& viesti) {
        Seuraaja* current = seuraajat;
        while (current != nullptr) {
            current->paivita(viesti);
            current = current->next;
        }
    }
};

int main() {
    Notifikaattori notifikaattori;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    notifikaattori.lisaa("A");
    notifikaattori.lisaa("B");
    notifikaattori.lisaa("C");

    std::cout << "Seuraajat:" << std::endl;
    notifikaattori.tulosta();

    std::cout << "Postitetaan viesti:" << std::endl;
    notifikaattori.postita("Hei kaikki!");

    notifikaattori.poista("B");

    std::cout << "Seuraajat B:n poiston jälkeen:" << std::endl;
    notifikaattori.tulosta();

    std::cout << "Postitetaan toinen viesti:" << std::endl;
    notifikaattori.postita("Moi taas!");

    return 0;
}