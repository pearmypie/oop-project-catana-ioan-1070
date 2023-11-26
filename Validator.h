#pragma once

// Catana Ioan-Alexandru, 25 nov 2023
// C++ implementation of the Luhn algorithm for validating ticket ID numbers
// The algorithm is in the public domain. It is specified in ISO/IEC 7812-1.
// Disclaimer: Luhn algirthm was designed to protect against accidental errors, 
// not malicious attacks.
// https://en.wikipedia.org/wiki/Luhn_algorithm

class Validator {
public:
	// fields
	enum {
		LAST_DIGIT,
		FIRST_DIGIT
	};

	// constructors, destructors
	Validator();
	~Validator();

	// methods
	static char compute_check_digit(const char* _payload);
	static char* generate_ticket_id(const char* _payload);
	static char* generate_ticket_id();
	static bool validate(const char* _ticket_id);
};

