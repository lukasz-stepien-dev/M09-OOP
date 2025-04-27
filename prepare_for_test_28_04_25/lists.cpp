//
// Created by lukas on 4/27/2025.
//
#include <iostream>

using namespace std;

struct Element {
    int value;
    Element* next;
};

void addOnBeginning(Element*& head, int value) {
    auto* newElement = new Element;
    newElement->value = value;
    newElement->next = head;
    head = newElement;
}

void printList(Element* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Element* head = nullptr;
    addOnBeginning(head, 1);
    addOnBeginning(head, 2);
    addOnBeginning(head, 3);
    printList(head);
    return 0;
}