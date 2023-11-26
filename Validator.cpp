#include<string>
#include "Validator.h"

// constructor, destructor
Validator::Validator() {
}

Validator::~Validator() {
}

// public methods
char Validator::compute_check_digit(const char* _payload) {
	/*
	The function assumes a character array of integers;
	The burden of input validation is on the caller.
	*/
	int sum = 0;
	char smod10;
	char result = 10;
	int length = strlen(_payload);

	for (int i = 1; i <= length; i++) {
		sum += _payload[length - i];
		if (i % 2 == 0)
			sum += _payload[length - i];
	}

	smod10 = sum % (char)10;
	result = 10 + smod10;

	return result;
}

char* Validator::generate_ticket_id(const char* _payload) {

}

char* Validator::generate_ticket_id() {

}

bool Validator::validate(const char* _ticket_id) {

}

