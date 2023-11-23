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

    // constructors, destructors
    Area();
    Area(char* _area_code, int _no_rows, Row* _rows);
    ~Area();
};

