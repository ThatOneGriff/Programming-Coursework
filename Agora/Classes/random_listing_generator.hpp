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
Listing get_random_listing(int job_type = -1);

#define CUSTOMER_LISTING   1
#define CONTRACTOR_LISTING 2



class _Job_Class
{
public:

	_Job_Class(const unsigned int _payment_LOW, const unsigned int _payment_HIGH, const std::vector<std::wstring>& _job_names)
	: payment_lower_bound(_payment_LOW), payment_upper_bound(_payment_HIGH), job_names(_job_names)
	{}

	std::wstring random_job_name()
	{
		return job_names[randint(0, job_names.size() - 1)];
	}

	int random_payment()
	{
		return randint(payment_lower_bound, payment_upper_bound);
	}

private:

	const unsigned int payment_lower_bound;
	const unsigned int payment_upper_bound;
	const std::vector<std::wstring> job_names;
};


_Job_Class cheap	   (150,    250,  {L"Уборщик",	   	   L"Дворник",		    L"Мойщик стёкол", L"Грузчик",			 L"Фасовщик",   L"Ремонт обуви"});
_Job_Class medium	   (251,    400,  {L"Водитель",		   L"Репетитор",        L"Бухгалтер",     L"Повар",				 L"Плотник",    L"Шитьё одежды",   L"Тренер"});
_Job_Class upper_med   (401,    750,  {L"Сварщик",		   L"Каменщик",		    L"Тестировщик",   L"Строитель",		     L"Садовник",   L"Ремонт техники", L"Джуниор-программист", L"Фотограф"});
_Job_Class lower_high  (751,   4000, {L"Мидл-программист", L"Администратор БД", L"Шофёр",	      L"Ремонт автотехники", L"Эксперт ИБ", L"Журналист"});
_Job_Class upper_high  (4001, 10000, {L"Личный охранник",  L"Экономист",		L"Статист",       L"Тимлид",			 L"Пилот"});



Listing get_random_listing(int job_type/* = -1*/)
{
	int category = randint(1, 5);

	std::wstring name = L"";
	unsigned int payment_hr = 0;
	switch(category)
	{
	case 1:
		name	   = cheap.random_job_name();
		payment_hr = cheap.random_payment();
		break;
	case 2:
		name	   = medium.random_job_name();
		payment_hr = medium.random_payment();
		break;
	case 3:
		name	   = upper_med.random_job_name();
		payment_hr = upper_med.random_payment();
		break;
	case 4:
		name	   = lower_high.random_job_name();
		payment_hr = lower_high.random_payment();
		break;
	case 5:
		name	   = upper_high.random_job_name();
		payment_hr = upper_high.random_payment();
		break;
	}

	int total_hrs = randint(1, 8);
	//const std::wstring time_unit = L"ч.";  // Not placeholder, yet not variable. Hence why it's const

	if (job_type == -1)
		job_type = randint(1, 2);
	/// Customer
	if (job_type == 1)
	{
		User *customer = PREDEFINED_COMPANIES[randint(9)];
		return Listing(name, total_hrs, payment_hr, nullptr, customer);
	}
	/// Contractor
	else if (job_type == 2)
	{
		// May not work due to pointers.
		Individual contractor = get_random_individual();
		return Listing(name, total_hrs, payment_hr, &contractor, nullptr);
	}
}

#endif