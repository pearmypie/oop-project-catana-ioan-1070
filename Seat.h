#pragma once
class Seat {
    bool free = true;

public:
    // class public interface
    void set_state(bool state);
    bool get_state();
    void flip_state();

    // constructors, destructors
    Seat() { }
    Seat(bool state) {
        set_state(true);
    }
    ~Seat() { }
};
