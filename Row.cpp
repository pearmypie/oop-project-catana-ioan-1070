#include "Row.h"
#include <string>

// accessors and mutators
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

// constructors and destructor
Row::Row() {

}

Row::Row(int _no_seats, Seat* _seats) {
    set_no_seats(_no_seats);
    set_seats(_seats);
}

Row::~Row() {
    delete[] this->seats;
}

// other methods
int Row::no_free_seats() {
	int no_free_seats = 0;

	for (int i = 0; i < this->no_seats; i++)
		if (this->seats[i].get_state())
			no_free_seats++;

	return no_free_seats;
}

int Row::no_reserved_seats() {
    return
        this->no_seats
        -
        no_free_seats()
        ;
}

double Row::occupancy_rate() {
	return 
        (double)no_reserved_seats()
        /
        (double)this->no_seats
        ;
}

// operator overloads
std::ostream& operator<<(std::ostream& os, const Row row) {
	os << "Row: " << row.no_seats << " seats" << std::endl;
	for (int i = 0; i < row.no_seats; i++)
		os << row.seats[i] << std::endl;
	return os;
}

std::ifstream& operator>>(std::ifstream& is, Row& row) {
    // to do
	return is;
}

Row& Row::operator=(const Row& row) {
	if (this != &row) {
		set_no_seats(row.no_seats);
		set_seats(row.seats);
	}
    else {
        if (this->seats != nullptr)
            delete[] this->seats;

        this->no_seats = row.no_seats;
        this->seats = new Seat[this->no_seats];
		memcpy(this->seats, row.seats, this->no_seats * sizeof Seat);
    }

    return *this;
}

bool Row::operator==(const Row& row) {
    return
        this->no_seats == row.no_seats
		&&
		this->seats == row.seats    // pointer comparison
		;
}

bool Row::operator!=(const Row& row) {
    return
        this->no_seats != row.no_seats
        &&
        this->seats != row.seats    // pointer comparison
        ;
}

bool Row::operator<(const Row& row) {
	return this->no_seats < row.no_seats;
}

bool Row::operator<=(const Row& row) {
	return this->no_seats <= row.no_seats;
}

bool Row::operator>(const Row& row) {
	return this->no_seats > row.no_seats;
}

bool Row::operator>=(const Row& row) {
	return this->no_seats >= row.no_seats;
}