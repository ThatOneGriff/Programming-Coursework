#pragma once
#ifndef DATE_TIME_HPP
#define DATE_TIME_HPP

#include <time.h> /// time
#include <string> /// 'std::wstring' 

///  Here be:
std::wstring get_date();
int get_time();


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