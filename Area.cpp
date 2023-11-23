#include "Area.h"
#include <string>

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