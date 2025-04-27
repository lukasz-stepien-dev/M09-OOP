// Format danych w pliku 'students.txt':
// - Pierwsza linia: liczba uczniów
// - Kolejne linie: nazwisko + 3 oceny z matematyki

// Co robi program?
// - Wczytuje dane uczniów z pliku
// - Oblicza średnią ocen dla każdego ucznia
// - Sortuje uczniów rosnąco według średniej przy użyciu sortowania bąbelkowego
// - Wyświetla wyniki przed i po sortowaniu
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream File("students.txt");
    if (!File) {
        cout << "Nie można otworzyć pliku!" << endl;
        return 1;
    }

    cout << "Hello, World!" << endl;
    return 0;
}