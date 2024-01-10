#define _CRT_SECURE_NO_WARNINGS
#include "App.h"
#include "Menu.h"
#include <string>

void App::run() {
    Menu::navigate();    
}

void App::set_seminar_professor(const char* _new) {
    if (_new) {
        this->seminar_professor = new char[strlen(_new) + 1];
        strcpy(
            this->seminar_professor,
            _new
        );
    }
}

char* App::get_seminar_professor() {
    char* result = new char[strlen(
        this->seminar_professor
    ) + 1];

    strcpy(
        result,
        this->seminar_professor
    );

    return result;
}