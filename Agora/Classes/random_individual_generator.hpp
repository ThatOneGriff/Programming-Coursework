#pragma once
#ifndef RANDOM_INDIVIDUAL_GENERATOR_HPP
#define RANDOM_INDIVIDUAL_GENERATOR_HPP

#include <string>
#include <vector>

#include "user.hpp"
#include "../utils.hpp"

/// Here be:
Individual get_random_individual();

std::wstring	_get_email(const Individual_Name& name);
Phone_Number    _get_random_phone_number(const bool corporate = false);
Individual_Name	_get_random_individual_name();


Individual get_random_individual()
{
	Individual_Name name = _get_random_individual_name();
	Date      birth_date = _get_random_date();
	Phone_Number  number = _get_random_phone_number();
	std::wstring   email = _get_email(name);

	Individual result(name, birth_date, number, email);
	return result;
}


#pragma region = Names =

const std::wstring names[30] = {
	L"���������", L"����",  L"�����",  L"������", L"�������", L"����",		  L"������",  L"�����",  L"�������", L"�������",
	L"����",	  L"�����",  L"����",   L"����",   L"������",  L"����������", L"���",	  L"������", L"����",	 L"������",
	L"�����",	  L"������", L"������", L"ϸ��",   L"�����",   L"������",	  L"�������", L"������", L"�����",   L"Ը���"
};
// PROBLEM: "��������" is causing problems (???)
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


#pragma region = Contacts =

const std::wstring _email_domains[3] = {L"gmail.com", L"mail.ru", L"yandex.ru"};
/// Random e-mails are ONLY FOR INDIVIDUALSs and are generated according to the name transliteration.
std::wstring _get_email(const Individual_Name& name)
{
	// igor_ivanov245@domain.com
	std::wstring body = translit_CtoL(name.name) + L'_'
					  + translit_CtoL(name.surname)
					  + std::to_wstring(randint(100, 999));
	std::wstring domain = _email_domains[randint(2)];

	return body + L'@' + domain;
}



// |    MTS	   |  BeeLine  |   Tele2   |   Misc   |
const int _carrier_code_limits[8][2] = {
	{910, 919}, {903, 909}, {900, 908}, {920, 937},
	{980, 989}, {960, 976}, {991, 999}, {800, 800}
};
Phone_Number _get_random_phone_number(const bool corporate/* = false*/)
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