#pragma once
#include "Row.h"
class Area {
    char* code;
    int no_rows;
    Row* rows;
public:
    // class public interface
    void set_code(char* area_code);
    char* get_code();

    void set_no_rows(int no_rows);
    int get_no_rows();

    void set_rows(Row* rows);
    Row* get_rows();

    // constructors, destructors
    Area() { }
    Area(char* area_code, int no_rows, Row* rows) {
        set_code(area_code);
        set_no_rows(no_rows);
        set_rows(rows);
    }
    ~Area() {
        delete[] code;
        delete[] rows;
    }
};

