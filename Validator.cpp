#define _CRT_SECURE_NO_WARNINGS
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
	The function assumes a character array of ASCII-encoded characters;
	The burden of input validation is on the caller.
	*/

	int sum = 0;
	int length = strlen(_payload);

	for (int i = 0; i < length; i++) {
		// we subtract 0x30 from each digit of the char array
		// in order to convert it from ASCII encoding to decimal
		char number = _payload[length - 1 - i] - 0x30;

		if (i % 2 == 0) {
			// if the position is even, the number is doubled
			number *= 2;

			// if the result is greater or equal to 10,
			// we need to compute the sum of the digits
			if (number > 9)
				number = number / 10 + number % 10;
		}

		sum += number;
	}

	char result = 10 - sum % 10 + 0x30;

	/*
	The function returns an ASCII-encoded character;
	This can be easily appended at the end of the payload.
	*/
	return result;
}

char* Validator::generate_ticket_id(const char* _payload) {
	return nullptr;
}

char* Validator::generate_ticket_id() {
	return nullptr;
}

bool Validator::validate(const char* _ticket_id) {
	int source_length = strlen(_ticket_id); // the number of characters in the string
	                                        // excluding the terminator character.
	int destination_length = source_length - 1;

	char last_digit = _ticket_id[source_length - 1];

	char* _payload = new char[strlen(_ticket_id)]; // intentionally omitting "+1",
	                                               // in order to obtain a shorter string
	strncpy_s(             // strncpy_s PARAMETERS 
		_payload,          // <-- DESTINATION
		source_length,     // <-- LENGTH OF SOURCE
		_ticket_id,        // <-- SOURCE
		destination_length // <-- HOW MANY CHARACTERS WE WISH TO COPY
	);
	_payload[destination_length] = 0; // <-- NULL HAS TO BE ADDED LATER

	char check_digit = compute_check_digit(_payload);
	bool result = last_digit == check_digit;
	return result;
}

