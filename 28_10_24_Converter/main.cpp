//
// Created by Łukasz Stępień on 28/10/2024.
//

#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

struct ConvertInfo {
    string fromUnit;
    double startValueUnit;
    string toUnit;
    double resultValue;
};




int main() {
    vector<ConvertInfo> converters;
    ConvertInfo converter;
    char choice;

    map<string, double> convert;
    convert.insert(make_pair("metry", 1));
    convert.insert(make_pair("centymetry", 0.01));
    convert.insert(make_pair("cale", 0.0254));
    convert.insert(make_pair("stopy", 0.3048));

    do {
        cout << "Podaj nazwe jednostkę początkową (metry, centymetry, cale, stopy): ";
        cin >> converter.fromUnit;
        cout << "Podaj wartość: ";
        cin >> converter.startValueUnit;
        cout << "Podaj nazwę jednostki docelowej (metry, centymetry, cale, stopy): ";
        cin >> converter.toUnit;

        const double meters = converter.startValueUnit * convert[converter.fromUnit];
        converter.resultValue = meters * convert[converter.toUnit];

        converters.push_back(converter);

        cout << "Czy chcesz dodać kolejną konwersje? (t/n)" << endl;
        cin >> choice;
    } while (choice == 't');


    cout << setfill('-') << setw(92) << " \n" << setfill(' ');
    cout << left << "| " << setw(20) << "Jednostka Początkowa" << " | " << right << setw(20) << "Wartość Początkowa" << " | " ;
    cout << left << setw(20) << "Jednostka Docelowa" << " | " << right << setw(20) << "Wynik konwersji" << " | " << endl;
    cout << setfill('-') << setw(92) << " \n" << setfill(' ');

    for (auto& info : converters) {
        cout << left << "| " << setw(20) << converter.fromUnit << " | " << right << setw(18) << converter.startValueUnit;
        cout << right << " | " << converter.toUnit << setw(19)  << " | " << right << setw(20) << converter.resultValue << " |" << endl; ;
    }

    cout << setfill('-') << setw(92) << " \n" << setfill(' ');
}
