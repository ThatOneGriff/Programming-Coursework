#pragma once
#ifndef DATE_TIME_HPP
#define DATE_TIME_HPP

#include <time.h> /// time
#include <string> /// 'std::wstring'
#include <vector>
#include "strings.hpp"

///  Here be:
class Date;
Date _get_random_date();
std::wstring get_date();
Date get_date_as_obj();
int get_time();

const std::wstring MONTHS_GENITIVE[12] = {
			 L"€нвар€",  L"феврал€",
L"марта",	 L"апрел€",  L"ма€",
L"июн€",	 L"июл€",	 L"августа",
L"сент€бр€", L"окт€бр€", L"но€бр€",
L"декабр€"};


class Date
{
public:

	Date()
	{/* default constructor for errors to shut up */}

	
	/// Out-of-file initialization
	Date(const std::wstring& _raw_date)
	{
		const std::vector<std::wstring> separated = separate(_raw_date);
		day   = _wtoi(separated[0].c_str());
		month = _wtoi(separated[1].c_str());
		year  = _wtoi(separated[2].c_str());
	}


	/// Registration
	Date(const unsigned int _day, const unsigned int _month, const unsigned int _year)
	: day(_day), month(_month), year(_year)
	{/* could run some checks on input values */}


	std::vector<std::wstring> as_vector()
	{
		const std::vector<std::wstring> result = {std::to_wstring(day), std::to_wstring(month), std::to_wstring(year)};
		return result;
	}


	std::wstring dd_mm_yyyy(const std::wstring separator = L".")
	{
		std::wstring dd = std::to_wstring(day);
		if (dd.size() < 2)
			dd = L"0" + dd;
		std::wstring mm = std::to_wstring(month);
		if (mm.size() < 2)
			mm = L"0" + mm;
		std::wstring yyyy = std::to_wstring(year);
		
		return dd + separator + mm + separator + yyyy;
	}


	std::wstring month_yyyy_genitive()
	{
		return MONTHS_GENITIVE[month - 1] + L" " + std::to_wstring(year) + L"г.";
	}


	int years_since(Date since = get_date_as_obj())
	{
		bool day_month_passed;
		if (since.month > this->month)
			day_month_passed = true;
		else if (since.month == this->month)
		{
			if (since.day >= this->day)
				day_month_passed = true;
			else
				day_month_passed = false;
		}
		else if (since.month < this->month)
			return day_month_passed = false;

		return since.year - this->year - ! day_month_passed;
	}

private:

	unsigned int day, month, year;
};


Date _get_random_date()
{
	int day   = randint(1, 28);
	int month = randint(1, 12);
	int year  = randint(1970, 2007);

	return Date(day, month, year);
}


std::wstring get_date()
{
	/// Copied from https://stackoverflow.com/a/68124506/15540979
	time_t rawtime;
	struct tm timeinfo;
	wchar_t buffer[20];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	wcsftime(buffer, 20, L"%d.%m.%Y", &timeinfo);
	return buffer;
}


Date get_date_as_obj()
{
	/// Copied from https://stackoverflow.com/a/68124506/15540979
	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	wchar_t day[4];
	wcsftime(day, 4, L"%d", &timeinfo);
	wchar_t month[4];
	wcsftime(month, 4, L"%m", &timeinfo);
	wchar_t year[8];
	wcsftime(year, 8, L"%Y", &timeinfo);

	Date date(_wtoi(day), _wtoi(month), _wtoi(year));
	return date;
}


int get_time()
{
	/// Copied from https://stackoverflow.com/a/68124506/15540979
	time_t rawtime;
	struct tm timeinfo;
	wchar_t buffer[20];

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	wcsftime(buffer, 20, L"%H%M%S", &timeinfo);

	return std::stoi(buffer);
}


#endif