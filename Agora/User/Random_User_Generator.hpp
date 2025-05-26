#pragma once
#ifndef RANDOM_USER_GENERATOR_HPP
#define RANDOM_USER_GENERATOR_HPP

#include "User.hpp"

//Email		 _get_random_email(std::wstring domain/* = L""*/); // email must be generated according to the name transliteration
Phone_Number	_get_random_phone_number(const bool corporate/* = false*/);
Individual_Name	_get_random_individual_name();



#pragma region = Helper functions =

const std::wstring names[30] = {
	L"Александр", L"Артём",  L"Вадим",  L"Виктор", L"Георгий", L"Глеб",		  L"Даниил",  L"Данил",  L"Дмитрий", L"Евгений",
	L"Егор",	  L"Захар",  L"Иван",   L"Илья",   L"Кирилл",  L"Константин", L"Лев",	  L"Леонид", L"Марк",	 L"Матвей",
	L"Мирон",	  L"Михаил", L"Никита", L"Пётр",   L"Роман",   L"Руслан",	  L"Савелий", L"Степан", L"Тихон",   L"Фёдор"
};
const std::wstring second_names[30] = {
	L"Андреев",	   L"Беляев", L"Васильев", L"Валерьев", L"Волков",	 L"Высоцкий", L"Горохов",  L"Гришин",   L"Громов",  L"Зайцев",
	L"Захарченко", L"Иванов", L"Киселев",  L"Козлов",	L"Копылов",  L"Миронов",  L"Моисеев",  L"Носов",	L"Орлов",   L"Павлов",
	L"Панов",	   L"Петров", L"Семенов",  L"Смирнов",  L"Соловьев", L"Степанов", L"Тимофеев", L"Трофимов", L"Устинов", L"Яковлев"
};
const std::wstring patronyms[30] = {
	L"Александр", L"Артём",  L"Вадим",  L"Виктор", L"Георгий", L"Глеб",		  L"Даниил",  L"Данил",  L"Дмитрий", L"Евгений",
	L"Егор",	  L"Захар",  L"Иван",   L"Илья",   L"Кирилл",  L"Константин", L"Лев",	  L"Леонид", L"Марк",	 L"Матвей",
	L"Мирон",	  L"Михаил", L"Никита", L"Пётр",   L"Роман",   L"Руслан",	  L"Савелий", L"Степан", L"Тихон",   L"Фёдор"
};
Individual_Name _get_random_individual_name()
{
	Individual_Name result(L"", L"", L"");
	return result;
}


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