#pragma once
#ifndef RANDOM_USER_GENERATOR_HPP
#define RANDOM_USER_GENERATOR_HPP

#include "User.hpp"

//Email		 _get_random_email(std::wstring domain/* = L""*/); // email must be generated according to the name transliteration
Phone_Number	_get_random_phone_number(const bool corporate/* = false*/);
Individual_Name	_get_random_individual_name();
//Company_Name   _get_random_company_name(); // As for that, I suppose I will just have a set of predefined companies.



#pragma region = Names =

const std::wstring names[30] = {
	L"���������", L"����",  L"�����",  L"������", L"�������", L"����",		  L"������",  L"�����",  L"�������", L"�������",
	L"����",	  L"�����",  L"����",   L"����",   L"������",  L"����������", L"���",	  L"������", L"����",	 L"������",
	L"�����",	  L"������", L"������", L"ϸ��",   L"�����",   L"������",	  L"�������", L"������", L"�����",   L"Ը���"
};
const std::wstring surnames[30] = {
	L"�������",	   L"������", L"��������", L"��������", L"������",	 L"��������", L"�������",  L"������",   L"������",  L"������",
	L"����������", L"������", L"�������",  L"������",	L"�������",  L"�������",  L"�������",  L"�����",	L"�����",   L"������",
	L"�����",	   L"������", L"�������",  L"�������",  L"��������", L"��������", L"��������", L"��������", L"�������", L"�������"
};
const std::wstring patronyms[30] = {
	L"�������������", L"��������",  L"���������", L"����������", L"����������", L"��������",		L"����������", L"���������",  L"����������", L"����������",
	L"��������",	  L"���������",  L"��������",  L"�����",      L"����������", L"��������������", L"����������", L"��������",	  L"���������",  L"���������"
	L"���������",	  L"����������", L"���������", L"ϸ������",   L"���������",  L"����������",	    L"����������", L"����������", L"���������",  L"Ը�������"
};
Individual_Name _get_random_individual_name()
{
	std::wstring name	  = names[randint(29)];
	std::wstring surname  = surnames[randint(29)];
	std::wstring patronym = patronyms[randint(29)];

	Individual_Name result(name, surname, patronym);
	return result;
}

#pragma endregion



#pragma region = Contacts

// |    MTS	   |  BeeLine  |   Tele2   |   Misc   |
const int _carrier_code_limits[8][2] = {
	{910, 919}, {903, 909}, {900, 908}, {920, 937},
	{980, 989}, {960, 976}, {991, 999}, {800, 800}
};
Phone_Number _get_random_phone_number(const bool corporate = false)
{
	int operator_type = randint(6 + corporate); // so that individuals don't get a 800 [i = 7] operator code
	int code = randint(_carrier_code_limits[operator_type][0], _carrier_code_limits[operator_type][1]);
	std::wstring carrier_code = std::to_wstring(code);

	std::wstring body;
	for (int i = 0; i < 7; i++)
		body += (L'0' + randint(9));
	
	Phone_Number result(L"+7", carrier_code, body);
	return result;
}

#pragma endregion


#endif