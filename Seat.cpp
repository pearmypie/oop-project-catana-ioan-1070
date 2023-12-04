#include "Seat.h"

// accessors and mutators
void Seat::set_state(bool _new_state) {
    this->free = _new_state;
}

bool Seat::get_state() {
    return this->free;
}

void Seat::set_exclusive_online(bool _new_state) {
	this->exclusive_online = _new_state;
}

bool Seat::get_exclusive_online() {
	return this->exclusive_online;
}

// other methods
void Seat::flip_state() {
    this->free = !(this->free);
}

void Seat::toggle_exclusive_online() {
	this->exclusive_online = !(this->exclusive_online);
}

// constructors and destructors
Seat::Seat() {

}

Seat::Seat(bool _state) {
    Seat::set_state(_state);
}

Seat::~Seat() {

}

// operators
Seat& Seat::operator=(const Seat& _other) {
	this->free = _other.free;
	this->exclusive_online = _other.exclusive_online;
	return *this;
}

bool Seat::operator==(const Seat& _other) {
	return 
		(this->free == _other.free) 
		&&
		(this->exclusive_online == _other.exclusive_online)
		;
}

bool Seat::operator!=(const Seat& _other) {
	return
		(this->free != _other.free)
		&&
		(this->exclusive_online != _other.exclusive_online)
		;
}

bool Seat::operator!() {
	return !(this->free);
}

std::ostream& operator<<(std::ostream& _os, Seat _seat) {
	_os << "Seat: " << _seat.free;
	_os << "Exclusive Online: " << _seat.exclusive_online;
	return _os;
}

std::istream& operator>>(std::istream& _is, Seat& _seat) {
	_is >> _seat.free;
	_is >> _seat.exclusive_online;
	return _is;
}

//explicit Seat::operator bool() {
//	return this->free;
//}
