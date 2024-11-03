//
// Created by Łukasz Stępień
//


#include <iostream>
#include <map>

class ComputerShop {
private:
    std::map<std::string, double> inventory;
protected:
    bool hasPart(std::string name) {
        return inventory.find(name) != inventory.end();
    }
public:
    std::string add(std::string name, double price) {
        inventory[name] = price;
        return "Dodano czesc";
    }

    std::string remove(std::string name) {
        if (!hasPart(name)) {
            return "Nie ma takiej czesci";
        }
        inventory.erase(name);
        return "Usunieto czesc";
    }

    void showAll() {
        for (auto& part : inventory) {
            std::cout << part.first << " - " << part.second << "PLN" << std::endl;
        }
    }

    double getPrice(std::string name) {
        if (!hasPart(name)) {
            std::cout << "Nie ma takiej czesci" << std::endl;
            return -1;
        }
        return inventory[name];
    }
};

int main()
{
    ComputerShop shop;
    int choice;
    do {
        std::cout << "1. Dodaj czesc" << std::endl;
        std::cout << "2. Usun czesc" << std::endl;
        std::cout << "3. Wyswietl wszystkie czesci" << std::endl;
        std::cout << "4. Sprawdz cene" << std::endl;
        std::cout << "5. Zakoncz" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                double price;
                std::cout << "Podaj nazwe czesc: ";
                std::cin >> name;
                std::cout << "Podaj cene czesci: ";
                std::cin >> price;
                std::cout << shop.add(name, price) << std::endl;
                break;
            }
            case 2: {
                std::string nameToRemove;
                std::cout << "Podaj nazwe czesci do usuniecia: ";
                std::cin >> nameToRemove;
                std::cout << shop.remove(nameToRemove) << std::endl;
                break;
            }
            case 3: {
                shop.showAll();
                break;
            }
            case 4: {
                std::string nameToCheck;
                std::cout << "Podaj nazwe czesc do sprawdzenia ceny: ";
                std::cin >> nameToCheck;
                double pricePart = shop.getPrice(nameToCheck);
                if (pricePart != -1) {
                    std::cout << "Cena czesci: " << pricePart << "PLN" << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Koniec programu" << std::endl;
                break;
            }
        }
    } while (choice != 5);
}