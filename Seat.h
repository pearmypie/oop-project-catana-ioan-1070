#pragma once
#include <iostream>

class Seat {
    bool free = true;
    bool exclusive_online = false;

public:
    // class public interface
    void set_state(bool _new_state);
    bool get_state();

    void set_exclusive_online(bool _new_state);
    bool get_exclusive_online();

    // generic methods
    void flip_state();
    void toggle_exclusive_online();

    // constructors, destructors
    Seat();
    Seat(bool _state);
    ~Seat();

    // operators
    friend std::ostream& operator <<(std::ostream&, Seat);
    friend std::istream& operator >>(std::istream&, Seat&);
    Seat& operator = (const Seat& other);
    bool operator == (const Seat& other);
    bool operator != (const Seat& other);
    bool operator ! ();
    explicit operator bool();
};
