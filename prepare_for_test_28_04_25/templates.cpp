//
// Created by lukas on 4/27/2025.
//
#include <iostream>
#include <utility>

using namespace std;

template <typename T> class List {
    T* array;
    unsigned short size = 0;
    unsigned short capacity = 10;
public:
    List() {
        array = new T[capacity];
    }
    ~List() {
        delete[] array;
    }
    void add(T value) {
         if (size < capacity)
            array[size++] = std::move(value);
         else
             cout << "List is full!" << endl;

    }
    void changeCapacity(unsigned short newCapacity) {
        if (newCapacity > capacity) {
            T* newArray = new T[newCapacity];
            for (unsigned short i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            capacity = newCapacity;
        } else {
            cout << "New capacity must be greater than current capacity!" << endl;
        }
    }

    void print() {
        for (unsigned short i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    List<int> list;
    list.add(5);
    list.add(10);
    list.add(15);

    List<string> stringList;
    stringList.add("Hello");
    stringList.add("World");

    cout << "Integer List: ";
    list.print();
    cout << endl;
    cout << "String List: ";
    stringList.print();
    return 0;
}