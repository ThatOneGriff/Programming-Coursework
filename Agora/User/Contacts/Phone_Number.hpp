#pragma once
#ifndef PHONE_NUMBER_HPP
#define PHONE_NUMBER_HPP

#include <iostream>
#include <string>
#include "../../Utils.hpp"

/// - The concept of a phone number;
/// - Random phone-number generator.

class Phone_Number;
std::string _get_random_carrier_code(const bool corporate = false);



//NOTE: current implementation is de-facto constant.
class Phone_Number
{
public:
	// bot (randomly generated)
	Phone_Number()
	: country_code("+7"), carrier_code(_get_random_carrier_code())
	{
		for (int i = 0; i < 7; i++)
			body += ('0' + randint(9));
	}

	// human (registration)
	Phone_Number(const std::string& _country_code, const std::string& _operator_code, const std::string& _body)
	: country_code(_country_code), carrier_code(_operator_code), body(_body)
	{}

	// +7 (123) 456-78-90
	std::string as_text()
	{
		std::string number_formatted = body;
		number_formatted.insert(3, "-");
		number_formatted.insert(6, "-"); // offset of 1 from the previous insert
		return country_code + " (" + carrier_code + ") " + number_formatted;
	}

	// +7 (123) ***-**-90
	std::string concealed()
	{
		std::string concealed_num = this->as_text();
		for (int i = concealed_num.size() - 4; i >= concealed_num.size() - 9; i--)
		{
			if (concealed_num[i] != '-')
				concealed_num[i] = '*';
		}
		return concealed_num;
	}

private:
	const std::string country_code,
					  carrier_code;
		  std::string body;
};



// TODO: refactor
std::string _get_random_carrier_code(const bool corporate/*= false*/)
{
	int operator_type = randint(7 + corporate); // so that individuals don't get a (800) operator code
	int code = -1;

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