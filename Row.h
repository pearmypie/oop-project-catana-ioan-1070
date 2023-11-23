#pragma once
#include "Seat.h"
class Row {
    int no_seats;
    Seat* seats;
public:
    // class public interface
    void set_no_seats(int _no_seats);
    int get_no_seats();

    void set_seats(Seat* _seats);
    Seat* get_seats();

    // constructors, destructors
    Row();
    Row(int _no_seats, Seat* _seats);
    ~Row();
};

