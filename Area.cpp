#include "Area.h"
#include <string>

// accessors
void Area::set_code(char* _area_code) {
    if (_area_code) {
        this->code = new char[strlen(_area_code) + 1];
        strcpy_s(this->code, strlen(_area_code) + 1, _area_code);
    }
}

char* Area::get_code() {
    return this->code;
}

void Area::set_no_rows(int _no_rows) {
    if (_no_rows)
        this->no_rows = _no_rows;
}

int Area::get_no_rows() {
    return this->no_rows;
}

void Area::set_rows(Row* _rows) {
    this->rows = new Row[this->no_rows];
    if (_rows)
        for(int i = 0; i < this->no_rows; i++)
            memcpy(
                &this->rows[i], 
                &_rows[i], 
                _rows[i].get_no_seats() * sizeof Seat
            );
}

Row* Area::get_rows() {
    return nullptr;
}


// constructors & destructor
Area::Area() {

}

Area::Area(char* _area_code, int _no_rows, Row* _rows) {
    set_code(_area_code);
    set_no_rows(_no_rows);
    set_rows(_rows);
}

Area::~Area() {
    delete[] this->code;
    delete[] this->rows;
}

// generic methods
int Area::get_capacity() {
    int capacity = 0;

    for (int i = 0; i < this->no_rows; i++)
	    capacity += this->rows[i].get_no_seats();

    return capacity;
}

int Area::get_no_seats_free() {
	int result = 0;

    for (int i = 0; i < this->no_rows; i++)
		result += this->rows[i].no_free_seats();

    return result;
}

int Area::get_no_seats_reserved() {
    return
        this->get_capacity()
        -
        this->get_no_seats_free()
        ;
}

// operators
std::ostream& operator<<(std::ostream& os, Area area) {
	os << "Area: " << area.code << std::endl;
	os << "Rows: " << area.no_rows << std::endl;
	os << "Capacity: " << area.get_capacity() << std::endl;
	os << "Free seats: " << area.get_no_seats_free() << std::endl;
	os << "Reserved seats: " << area.get_no_seats_reserved() << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Area& area) {
	// to do
	return is;
}

Area& Area::operator=(Area& area) {
    // to do
	if (this != &area) {
		//this->code = 
		this->no_rows = area.no_rows;
		//this->set_rows(area.get_rows());
    }
    else {
        if (this->rows != nullptr)
			delete[] this->rows;

        if (this->rows != nullptr)
            delete[] this->rows;

        strcpy(this->code, area.get_code());
        this->no_rows = area.no_rows;
        this->rows = area.get_rows();
    }

	return *this;
}

bool Area::operator==(Area& area) {
	return
		strcmp(this->code, area.code) == 0
		&&
		this->no_rows == area.no_rows
		&&
		this->get_capacity() == area.get_capacity()
		&&
		this->get_no_seats_free() == area.get_no_seats_free()
		&&
		this->get_no_seats_reserved() == area.get_no_seats_reserved()
		;
}

bool Area::operator!=(Area& area) {
	return !(*this == area);
}

bool Area::operator<(Area& area) {
    return this->get_capacity() < area.get_capacity();
}

bool Area::operator<=(Area& area) {
	return this->get_capacity() <= area.get_capacity();
}

bool Area::operator>(Area& area) {
	return this->get_capacity() > area.get_capacity();
}

bool Area::operator>=(Area& area) {
	return this->get_capacity() >= area.get_capacity();
}


