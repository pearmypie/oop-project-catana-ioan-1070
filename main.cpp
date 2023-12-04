//#include "App.h"
#include <iostream>
#include "Area.h"
#include "Location.h"
#include "Validator.h"

int main() {
    // testing
    char _payload[] = "1789372997";
    char _ticket_id[] = "17893729974";

    std::cout << Validator::compute_check_digit(_payload) << '\n';
    std::cout << _payload << '\n';
    std::cout << _ticket_id << '\n';

    if (Validator::validate(_ticket_id))
        std::cout << "Valid";
    else
        std::cout << "Invalid";
}