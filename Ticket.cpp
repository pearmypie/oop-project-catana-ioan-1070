#define _CRT_SECURE_NO_WARNINGS
#include "Ticket.h"
#include <string>

void Ticket::set_ID(char* _id) {
    if (_id)
        strcpy(this->ID, _id);
}

char* Ticket::get_ticket_ID() {
    char* result = new char[16];
    strcpy(result, this->ID);
    return result;
}
