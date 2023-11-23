#include "Row.h"
#include <string>

void Row::set_no_seats(int _no_seats) {
    if (_no_seats)
        this->no_seats = _no_seats;
}

int Row::get_no_seats() {
    return this->no_seats;
}

void Row::set_seats(Seat* _seats) {
    this->seats = new Seat[this->no_seats];
    if (_seats)
        memcpy(this->seats, _seats, this->no_seats * sizeof Seat);
}

Seat* Row::get_seats() {
    Seat* _seats = new Seat[this->no_seats];
    memcpy(_seats, this->seats, this->no_seats * sizeof Seat);
    return _seats;
}

Row::Row() {

}

Row::Row(int _no_seats, Seat* _seats) {
    set_no_seats(_no_seats);
    set_seats(_seats);
}

Row::~Row() {
    delete[] this->seats;
}