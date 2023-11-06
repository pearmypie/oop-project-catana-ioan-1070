#pragma once
#include "Seat.h"
class Row {
    int no_seats;
    Seat* seats;
public:
    // class public interface
    void set_no_seats(int no_seats);
    int get_no_seats();

    void set_seats(Seat* seats);
    Seat* get_seats();

    // constructors, destructors
    Row() { }
    Row(int no_seats, Seat* seats) {
        set_no_seats(no_seats);
        set_seats(seats);
    }
    ~Row() {
        delete[] this->seats;
    }
};

