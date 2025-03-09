#include "func.h"
#include<iostream>
using namespace std;
int main() {
    int choice;
    string dna;

    while (true) {
        cout << "Menu:\n";
        cout << "1 - Get GC Content\n";
        cout << "2 - Get DNA Complement\n";
        cout << "3 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter DNA string: ";
            cin >> dna;
            cout << "GC Content: " << get_gc_content(dna) << endl;
        } else if (choice == 2) {
            cout << "Enter DNA string: ";
            cin >> dna;
            cout << "DNA Complement: " << get_dna_complement(dna) << endl;
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
