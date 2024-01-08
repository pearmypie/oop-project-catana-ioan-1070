#include "Menu.h"
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

char Menu::get_option_from_user() {
    return _getch();
}

void Menu::navigate() {
    bool correct_selection = false;

    cout
        << "[B]uy a ticket to the event\n"
        << "[S]ee event details\n"
        << "[V]alidate ticket number\n"
        ;

    do {
        char selected = get_option_from_user();

        switch (selected) {
        case 'b':
            cout << "B\n";
            correct_selection = true;
            break;

        case 's':
            cout << "S\n";
            correct_selection = true;
            break;

        case 'v':
            cout << "V\n";
            correct_selection = true;
            break;

        default:
            cout << "Invalid input.\n";
        }

    } while (!correct_selection);
}