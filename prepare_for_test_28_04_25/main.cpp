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
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Students {
public:
    string surname;
    unsigned short* getGrades() {
        return this->grades;
    }

    void setGrades(const unsigned short* gradesToChange) {
        for (int i = 0; i < 3; ++i) {
            this->grades[i] = gradesToChange[i];
        }
    }

    void printGrades() {
        cout << "--------------------------" << endl;
        cout << this->surname << ": ";
        for (unsigned short & grade: grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

    double getAverage() {
        double sum = 0;
        for (unsigned short & grade : grades) {
            sum += grade;
        }
        return sum / 3;
    }

private:
    unsigned short grades[3];
};

Students* bubbleSort(Students* students, unsigned short numberOfStudents) {
    for (unsigned short i = 0; i < numberOfStudents; i++) {
        bool swapped = false;
        for (unsigned short j = 0; j < numberOfStudents - i - 1; j++) {
            if (students[j].getAverage() < students[j + 1].getAverage()) {
                swap(students[j], students[j + 1]);
                swapped = true;
            }
        }
    }
    return students;
}

int main() {
    ifstream File("students.txt");
    if (!File) {
        cout << "Nie można otworzyć pliku!" << endl;
        return 1;
    }

    string line;
    istringstream iss;
    unsigned short numberOfStudents = 0;

    if (getline(File, line)) {
        iss.str(line);
        iss >> numberOfStudents;
        iss.clear();
    }

    Students *students = new Students[numberOfStudents];
    unsigned short iterator = 0;

    while(getline(File, line) && iterator < numberOfStudents) {
        iss.str(line);
        iss >> students[iterator].surname;
        unsigned short grades[3] = {0};
        for (unsigned short & grade : grades) {
            iss >> grade;
        }
        students[iterator].setGrades(grades);
        iss.clear();
        iterator++;
    }

    cout << "Przed sortowaniem:" << endl;
    for (unsigned short i = 0; i < iterator; i++) {
        students[i].printGrades();
        cout << "Średnia: " << std::setprecision(4) << students[i].getAverage() << endl;
    }

    cout << "Po sortowaniu:" << endl;
    students = bubbleSort(students, numberOfStudents);
    for (unsigned short i = 0; i < iterator; i++) {
        students[i].printGrades();
        cout << "Średnia: " << std::setprecision(4) << students[i].getAverage() << endl;
    }
    delete [] students;
    return 0;
}