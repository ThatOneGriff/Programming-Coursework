#pragma once
#ifndef RANDOM_LISTING_GENERATOR
#define RANDOM_LISTING_GENERATOR

#include <string>
#include <vector>

#include "listing.hpp"
#include "user.hpp"
#include "random_individual_generator.hpp"
#include "../save_load.hpp"
#include "../utils.hpp"

/// Here be:
class  _Job_Class;
Listing get_random_listing(int job_type);



class _Job_Class
{
public:

	_Job_Class(const unsigned int _per_hr_LOW, const unsigned int _per_hr_HIGH, const std::vector<std::wstring>& _job_names)
	: per_hr_lower_bound(_per_hr_LOW), per_hr_upper_bound(_per_hr_HIGH), job_names(_job_names)
	{}

	std::wstring random_job_name()
	{
		return job_names[randint(0, job_names.size() - 1)];
	}

	int random_per_hr()
	{
		return randint(per_hr_lower_bound, per_hr_upper_bound);
	}

private:

	const unsigned int per_hr_lower_bound;
	const unsigned int per_hr_upper_bound;
	const std::vector<std::wstring> job_names;
};


_Job_Class cheap	   (150,    250,  {L"Уборщик",	   	   L"Дворник",		    L"Мойщик стёкол",  L"Грузчик",			  L"Фасовщик",   L"Ремонт обуви"});
_Job_Class medium	   (251,    400,  {L"Водитель",		   /*L"Репетитор",      L"Бухгалтер",      L"Повар",*/			  L"Плотник",    L"Фрезеровщик"/*,  L"Тренер"*/});
_Job_Class upper_med   (401,    750,  {L"Сварщик",		   L"Каменщик",		    L"Тестировщик ПО", L"Строитель",		/*L"Садовник",*/ L"Ремонт техники", L"Джуниор-программист"/*, L"Фотограф"*/});
_Job_Class lower_high  (751,   4000, {L"Мидл-программист", L"Администратор БД", L"Шофёр",	       L"Ремонт автотехники", L"Эксперт ИБ"/*, L"Журналист"*/});
_Job_Class upper_high  (4001, 10000, {L"Личный охранник",  L"Экономист",		L"Статист",        L"Тимлид",			  L"Пилот"});



Listing get_random_listing(int job_type)
{
	int category = randint(1, 5);

	std::wstring name = L"";
	unsigned int per_hr = 0;
	switch(category)
	{
	case 1:
		name   = cheap.random_job_name();
		per_hr = cheap.random_per_hr();
		break;
	case 2:
		name   = medium.random_job_name();
		per_hr = medium.random_per_hr();
		break;
	case 3:
		name   = upper_med.random_job_name();
		per_hr = upper_med.random_per_hr();
		break;
	case 4:
		name   = lower_high.random_job_name();
		per_hr = lower_high.random_per_hr();
		break;
	case 5:
		name   = upper_high.random_job_name();
		per_hr = upper_high.random_per_hr();
		break;
	}

	/// Customer
	if (job_type == CUSTOMER_LISTING)
	{
		User *customer = PREDEFINED_COMPANIES[randint(9)];
		int hrs = randint(1, 8);
		return Listing(name, hrs, per_hr, nullptr, customer);
	}
	/// Contractor
	else if (job_type == CONTRACTOR_LISTING)
	{
		return Listing(name, 1, per_hr, get_random_individual(), nullptr);
	}
}

#endif