#pragma once
#include "Menu.h"
#include <print>
class App {
    //char* student;
    char* seminar_professor;
public:
    // class public interface
    //void set_student(char* new_student);
    //char* get_student();

    void set_seminar_professor(char* new_professor);
    char* get_seminar_professor();

    // constructors, destructors
    App() {}
    ~App() {
        delete[] seminar_professor;
    }

    // member functions
    void run();
};

