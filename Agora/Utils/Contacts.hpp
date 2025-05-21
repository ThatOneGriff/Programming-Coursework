#pragma once
#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <string>
#include "Utils.hpp"


std::string _get_random_operator_code(const bool corporate = false);

class Phone_Number
{
public:

	// generate random
	Phone_Number()
	: country_code("+7"), operator_code(_get_random_operator_code())
	{
		for (int i = 0; i < 7; i++)
			number += ('0' + randint(9));
	}

	// registration
	Phone_Number(const std::string& _country_code, const std::string& _operator_code, const std::string& _number)
	: country_code(country_code), operator_code(_operator_code), number(_number)
	{}

private:
	std::string country_code;
	std::string operator_code;
	std::string number = "";
};



std::string _get_random_operator_code(const bool corporate = false)
{
	int operator_type = randint(7 + corporate); // so that individuals don't get a (800) operator code
	int code;

	switch (operator_type)
	{
	case 1: // MTS-old
		code = randint(910, 919);
		break;
	case 2: // MTS-new
		code = randint(980, 989);
		break;
	case 3: // BeeLine-old
		code = randint(903, 909);
		break;
	case 4: // BeeLine-new
		code = randint(960, 976);
		break;
	case 5: // MegaPhone
		code = randint(920, 937);
		break;
	case 6: // Tele2-old
		code = randint(900, 908);
		break;
	case 7: // Tele2-new
		code = randint(991, 999);
		break;
	case 8: // corporate
		code = 800;
	}

	return std::to_string(code);
}

#endif