#pragma once

class Location {
    char* address;
public:
    // class public interface
    void set_address(char* new_address);
    char* get_address();

    // constructors, destructors
    Location() { }
    Location(char* new_address) {
        set_address(new_address);
    }
    ~Location() {
        delete[] address;
    }
};

