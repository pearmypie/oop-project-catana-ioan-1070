#pragma once
#include "Row.h"
class Area {
    char* code;
    int no_rows;
    Row* rows;
public:
    // class public interface
    void set_code(char* _area_code);
    char* get_code();

    void set_no_rows(int _no_rows);
    int get_no_rows();

    void set_rows(Row* _rows);
    Row* get_rows();

    // generic methods
    int get_capacity();
    int get_no_seats_free();
    int get_no_seats_reserved();

    // constructors, destructors
    Area();
    Area(char* _area_code, int _no_rows, Row* _rows);
    ~Area();

    // operators
    friend std::ostream& operator<<(std::ostream& os, Area area);
    friend std::istream& operator>>(std::istream& is, Area& area);
    Area& operator=(Area& area);
    bool operator==(Area& area);
    bool operator!=(Area& area);
    bool operator<(Area& area);
    bool operator<=(Area& area);
	bool operator>(Area& area);
	bool operator>=(Area& area);
};

