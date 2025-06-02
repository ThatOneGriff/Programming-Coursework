#pragma once
#ifndef PHONE_NUMBER_HPP
#define PHONE_NUMBER_HPP

#include <string>
#include "../../Utils.hpp"

/// - The concept of a phone number.
class Phone_Number;


class Phone_Number
{
public:
	
	Phone_Number(const std::wstring& _country_code, const std::wstring& _carrier_code, const std::wstring& _body)
	: country_code(_country_code), carrier_code(_carrier_code), body(_body)
	{}

	// +7 (123) 456-78-90
	std::wstring as_text()
	{
		std::wstring number_formatted = body;
		number_formatted.insert(3, L"-");
		number_formatted.insert(6, L"-"); // offset of 1 from the previous insert
		return country_code + L" (" + carrier_code + L") " + number_formatted;
	}

	// +7 (123) ***-**-90
	std::wstring concealed()
	{
		std::wstring concealed_num = this->as_text();
		for (unsigned int i = concealed_num.size() - 4; i >= concealed_num.size() - 9; i--)
		{
			if (concealed_num[i] != L'-')
				concealed_num[i] = L'*';
		}
		return concealed_num;
	}

private:
	const std::wstring country_code,
					   carrier_code;
		  std::wstring body;
};


#endif