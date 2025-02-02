#include <iostream>
using namespace std;

class Pankkitili {
protected:
    double saldo;

public:
    Pankkitili() : saldo(0) {}

    virtual bool deposit(double amount) {
        if (amount < 0) return false;
        saldo += amount;
        return true;
    }

    virtual bool withdraw(double amount) {
        if (amount < 0 || amount > saldo) return false;
        saldo -= amount;
        return true;
    }

    double getBalance() const {
        return saldo;
    }
};


class Luottotili : public Pankkitili {
private:
    double luottoraja;

public:
    Luottotili(double raja) : luottoraja(raja) {}

    bool withdraw(double amount) override {
        if (amount < 0 || saldo - amount < -luottoraja) return false;
        saldo -= amount;
        return true;
    }

    bool payCredit(double amount) {
        if (amount < 0 || saldo + amount > 0) return false;
        saldo += amount;
        return true;
    }
};

class Asiakas {
private:
    Pankkitili pankkitili;
    Luottotili luottotili;

public:
    Asiakas(double luottoraja) : luottotili(luottoraja) {}

    void showSaldo() const {
        cout << "Pankkitilin saldo: " << pankkitili.getBalance() << endl;
        cout << "Luottotilin saldo: " << luottotili.getBalance() << endl;
    }

    bool talletus(double amount) {
        return pankkitili.deposit(amount);
    }

    bool nosto(double amount) {
        return pankkitili.withdraw(amount);
    }

    bool luotonMaksu(double amount) {
        return luottotili.payCredit(amount);
    }

    bool luotonNosto(double amount) {
        return luottotili.withdraw(amount);
    }

    bool tiliSiirto(double amount, Asiakas &kohde) {
        if (amount < 0 || !pankkitili.withdraw(amount)) return false;
        return kohde.talletus(amount);
    }
};


int main() {
    Asiakas asiakas1(500);
    Asiakas asiakas2(300);

    asiakas1.talletus(1000);
    asiakas1.nosto(200);
    asiakas1.luotonNosto(300);
    asiakas1.luotonMaksu(100);

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    if (asiakas1.tiliSiirto(100, asiakas2)) {
        cout << "Siirto onnistui!" << endl;
    } else {
        cout << "Siirto epäonnistui!" << endl;
    }

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    return 0;
}

