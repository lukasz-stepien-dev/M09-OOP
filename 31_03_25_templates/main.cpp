#include <iostream>
using namespace std;

class Pudelko {
private:
    int zawartosc;
public:
    Pudelko(int zawartosc) {
        this->zawartosc = zawartosc;
    }

    int pobierz() {
        return zawartosc;
    }

    void ustaw(int nowaZawartosc) {
        zawartosc = nowaZawartosc;
    }

    void wyswietlInfo() {
        cout << "Typ danych: " << typeid(zawartosc).name() << ", zawartosc: " << zawartosc << endl;
    }
};

template <typename T>
class List {
private:
    T* elements = nullptr;
    int elementsCount = 0;
public:
    // Constructor
    explicit List(const int size) {
        elements = new T[size];
    }

    ~List() {
        delete[] elements;
    }

    void add(T element) {
        elements[elementsCount] = element;
        elementsCount++;
    }

    void display() {
        cout << "Lista: ";
        for (int i = 0; i < elementsCount; i++) {
            cout << elements[i] << " ";
        }
    }
};

int main() {
    List<int> list(3);
    list.add(1);
    list.add(2);
    list.add(3);
    list.display();

    List<string> listString(3);
    listString.add("C++");
    listString.add("Szablony");
    listString.add("Klasy");
    listString.display();

    return 0;
}
