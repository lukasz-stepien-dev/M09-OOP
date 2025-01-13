#include <iostream>
#include <set>
#include <string>

using namespace std;

bool is_user_exist(const set<string> &list, const string &name) {
    return list.find(name) != list.end();
}

bool add_user(set<string> &list, const string &name) {
    if (!is_user_exist(list, name)) { // Change to check if user does not exist
        list.insert(name);
        return true;
    }
    return false;
}

bool remove_user(set<string> &list, const string &name) {
    if (is_user_exist(list, name)) {
        list.erase(name);
        return true;
    }
    return false;
}

void show_list(const set<string> &list) {
    for (const auto &user : list) { // Use 'const auto&' to avoid copying
        cout << user << endl;
    }
}

int main() {
    set<string> users;
    unsigned short choice = 0;
    string name; // Declare 'name' outside of switch

    do {
        cout << "1. Dodaj uczestnika" << endl;
        cout << "2. Usun uczestnika" << endl;
        cout << "3. Wyswietl liste uczestnikow" << endl;
        cout << "4. Sprawdz, czy uczestnik jest zapisany" << endl;
        cout << "5. Zakoncz" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Podaj imie: ";
                cin >> name;
                if (add_user(users, name)) {
                    cout << "Uczestnik dodany." << endl;
                } else {
                    cout << "Uczestnik już istnieje." << endl;
                }
                break;

            case 2:
                cout << "Podaj imie: ";
                cin >> name;
                if (remove_user(users, name)) {
                    cout << "Uczestnik usunięty." << endl;
                } else {
                    cout << "Uczestnik nie istnieje." << endl;
                }
                break;

            case 3:
                show_list(users);
                break;

            case 4:
                cout << "Podaj imie: ";
                cin >> name;
                if (is_user_exist(users, name)) {
                    cout << "Uczesnik o imieniu " << name << " istnieje" << endl;
                } else {
                    cout << "Uczesnik o imieniu " << name << " nie istnieje" << endl;
                }
                break;

            default:
                choice = 5;
                break;
        }
    } while (choice != 5);

    return 0;
}
