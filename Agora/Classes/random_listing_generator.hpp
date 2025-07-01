#pragma once
#ifndef LISTING_RANDOM_GENERATOR
#define LISTING_RANDOM_GENERATOR

#include <string>
#include <vector>

#include "listing.hpp"
#include "user.hpp"
#include "random_individual_generator.hpp"
#include "../utils.hpp"

/// Here be:
class  _Job_Class;
Listing get_random_listing();


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


_Job_Class cheap	    (75,  125,  {L"Уборщик",		  L"Дворник",		   L"Мойщик стёкол", L"Грузчик",			L"Фасовщик",   L"Ремонт обуви"});
_Job_Class medium	   (126,  200,  {L"Водитель",		  L"Репетитор",        L"Бухгалтер",     L"Тренер",             L"Повар",      L"Плотник",        L"Шитьё одежды"});
_Job_Class upper_med   (201,  375,  {L"Сварщик",		  L"Каменщик",		   L"Тестировщик",   L"Строитель",		    L"Садовник",   L"Ремонт техники", L"Джуниор-программист", L"Фотограф"});
_Job_Class lower_high  (376,  2000, {L"Мидл-программист", L"Администратор БД", L"Шофёр",	     L"Ремонт автотехники", L"Эксперт ИБ", L"Журналист"});
_Job_Class upper_high  (2001, 5000, {L"Личный охранник",  L"Экономист",		   L"Статист",       L"Тимлид",				L"Пилот"});


Listing get_random_listing()
{
	int category = randint(1, 5);

	std::wstring name;
	unsigned int payment_hr;
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

	Date until = _get_random_date(); // PLACEHOLDER
	const std::wstring time_unit = L"ч.";  // Not placeholder, yet not variable. Hence why it's const
	
	/// Flipping a coin to see if we'll have a contractor or a customer.
	if (randint(1, 2) == 1) /// Contractor
	{
		/// [NOT TRUE] Flipping it again to see if it's a 'Company' or an 'Individual'.
		// TODO: predefined list of companies.
		/*if (randint(1, 2) == 1) /// Company
		{
			Company contractor()
		}*/

		// Prepared indent
		{
			// Most probably will not work due to pointers.
			Individual *contractor = &get_random_individual();
			// GIVING 'payment_hr' INSTEAD OF 'payment_full'
			return Listing(name, until, payment_hr, contractor);
		}
	}
	else /// Customer
	{
		// Same things about Company as in Contractor region of this func.
		{
			Individual *customer = &get_random_individual();
			// GIVING 'payment_hr' INSTEAD OF 'payment_full'
			return Listing(name, until, payment_hr, nullptr, customer);
		}
	}
}


#endif