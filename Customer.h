#pragma once
class Customer
{
	char* name;
public:
	// public interface
	char* get_name();
	void set_name(char* name);

// constructors
	Customer();
	Customer(const Customer& other);
	~Customer();
};

