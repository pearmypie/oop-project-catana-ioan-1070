#include "Seat.h"

void Seat::set_state(bool _new_state) {
    this->free = _new_state;
}

bool Seat::get_state() {
    return this->free;
}

void Seat::flip_state() {
    this->free = !(this->free);
}

Seat::Seat() {

}

Seat::Seat(bool _state) {
    Seat::set_state(_state);
}

Seat::~Seat() {

}