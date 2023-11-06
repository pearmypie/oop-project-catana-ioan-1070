#include "Seat.h"

void Seat::set_state(bool new_state) {
    this->free = new_state;
}

bool Seat::get_state() {
    return this->free;
}

void Seat::flip_state() {
    this->free = !(this->free);
}