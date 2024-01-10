#include "Menu.h"
#include "Validator.h"
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

char Menu::get_option_from_user() {
    // very useful member function,
    // that provides incredible functionality
    // and clarity enhancements.
    // the world is better, thanks to this
    // function.
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
            char buffer[100];

            cout << "Input Ticket ID #:";
            cin >> buffer;

            if (Validator::validate(buffer)) {
                cout << "Your Ticket ID is valid.";
                // to do: look it up in a DB file
                // to do: add length check
            }
            else {
                cout << "Your Ticket ID is invalid.";
            }

            correct_selection = true;
            break;

        default:
            cout << "Invalid input.\n";
        }

    } while (!correct_selection);
}