//
// Created by Łukasz Stępień on 13/01/2025.
//
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;



int main() {
    string text;
    cout << "Podaj tekst: " << endl;
    getline(cin, text);
    stringstream ss(text);
    unordered_map<string, unsigned short int> words;
    string word;
    while (ss >> word) {
        words[word]++;
    }
    for (const auto & p : words) {
      cout << p.first << " " << p.second << endl;
    }
}