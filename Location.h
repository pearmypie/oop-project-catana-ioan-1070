#pragma once
#include "Area.h"
class Location {
    char* path;
    char* address;

    int no_areas;
    Area* areas;
public:
    // class public interface
    void set_path(char* new_path);
    char* get_path();

    void set_address(char* new_address);
    char* get_address();

    void set_no_areas(int new_no_areas);
    int get_no_areas();

    void set_areas(Area* new_areas);
    Area* get_areas();

    // constructors, destructors
    Location() { }
    Location(char* new_address) {
        set_path(new_address);
        set_address(new_address);
    }
    ~Location() {
        delete[] path;
        delete[] address;
    }
};

