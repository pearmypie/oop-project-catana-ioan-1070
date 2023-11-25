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

    // generic methods
    int no_free_seats();
    int no_reserved_seats();
    double occupancy_rate();

    // constructors, destructors
    Row();
    Row(int _no_seats, Seat* _seats);
    ~Row();

    // operators
    friend std::ostream& operator <<(std::ostream&, Row);
    friend std::istream& operator >>(std::istream&, Row&);
    Row& operator =(const Row&);
    bool operator ==(const Row&);
    bool operator !=(const Row&);
    bool operator <(const Row&);
    bool operator >(const Row&);
    bool operator <=(const Row&);
    bool operator >=(const Row&);
};

